


portTASK_FUNCTION(SoundTask, pvParameters )
{

	while (1) {
		/*
			배경음을 출력한다.
			상태에 따른 효과음을 출력한다.
		*/
		playData = getStatus();
		switch(playData.status){
			case BACKGROUND :
			break;
			case CAUGHT :
			break;
			case WIN :
			break;

			}
	}
}

void BackgroundSound()
{
		 mmInitDefaultMem((mm_addr) soundbank_bin);

	for (i = MSL_BANKSIZE; i > 0; i--)
		mmLoadEffect(i);
		 
		 mmEffectEx(&Do);
}

void WinSound()
{
		 mmInitDefaultMem((mm_addr) soundbank_bin);

		 	for (i = MSL_BANKSIZE; i > 0; i--)
		mmLoadEffect(i);
		 mmEffectEx(&Do);
}

void CaughtSound()
{
		 mmInitDefaultMem((mm_addr) soundbank_bin);
	for (i = MSL_BANKSIZE; i > 0; i--)
		mmLoadEffect(i);
		 
		 mmEffectEx(&Do);
}