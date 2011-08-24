#ifndef __TIMER_H__
#define __TIMER_H__

class timer
{
	private:
		int fps;
		int time;

	public:
		timer(int f);
		void sync(void);
};

#endif /* __TIMER_H__ */
