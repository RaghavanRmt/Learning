#include<stdio.h>
#include <sys/time.h>
#include <sys/timerfd.h>

#define TIMER_IN_MS			1000

struct dp_rwr_periodic_info
{
	int timer_fd;
	unsigned long long wakeups_missed;
};

int dp_rwr_make_periodic(unsigned int uiPeriod_us, struct dp_rwr_periodic_info *pTimerHandle);
void dp_rwr_wait_period(struct dp_rwr_periodic_info *pTimerHandle);

int main()
{
	struct dp_rwr_periodic_info m_iTimer;

	/*Configure the periodic timer*/
	dp_rwr_make_periodic(TIMER_IN_MS * 1000,&m_iTimer); 

	while(1)
	{
		printf("\r\nTest");
		dp_rwr_wait_period(&m_iTimer);	
	}

	return 0;
}

int dp_rwr_make_periodic(unsigned int uiPeriod_us, struct dp_rwr_periodic_info *pTimerHandle)
{
	int iRetVal = 0;
	unsigned int ui_ns = 0;
	unsigned int ui_sec = 0;
	int i_fdTimer = 0;
	struct itimerspec m_itval = {0};

	/* Create the timer */
	i_fdTimer = timerfd_create(CLOCK_MONOTONIC, 0);
	pTimerHandle->wakeups_missed = 0;
	pTimerHandle->timer_fd = i_fdTimer;
	
	if(i_fdTimer == -1)
	{
		return i_fdTimer;
	}

	/* Make the timer periodic */
	ui_sec = uiPeriod_us/1000000;
	ui_ns = (uiPeriod_us - (ui_sec * 1000000)) * 1000;
	
	m_itval.it_interval.tv_sec = ui_sec;
	m_itval.it_interval.tv_nsec = ui_ns;
	m_itval.it_value.tv_sec = ui_sec;
	m_itval.it_value.tv_nsec = ui_ns;
	
	iRetVal = timerfd_settime(i_fdTimer, 0, &m_itval, NULL);
	
	return iRetVal;
}

void dp_rwr_wait_period(struct dp_rwr_periodic_info *pTimerHandle)
{
	unsigned long long ul64_MissedCount;
	int iRetVal = 0;

	/* Wait for the next timer event. If we have ul64_MissedCount any the
	   number is written to "ul64_MissedCount" */
	iRetVal = read(pTimerHandle->timer_fd, &ul64_MissedCount, sizeof (ul64_MissedCount));
	if(iRetVal == -1)
	{
		perror ("read timer");
		return;
	}

	/* "ul64_MissedCount" should always be >= 1, but just to be sure, check it is not 0 anyway */
	if(ul64_MissedCount > 0)
	{
		pTimerHandle->wakeups_missed += (ul64_MissedCount - 1);
	}
}