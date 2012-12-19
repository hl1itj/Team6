

static
portTASK_FUNCTION(ImageTask, pvParameters )
{
	while (1) {
		playData = getStatus();

		PrintScreen(playData);
	}
}

void PrintScreen(PlayData playData)
{
	playData.x
	playData.y
	drawCharacter(playData.x, playData.y,playData.status);
	//1. 캐릭터좌표값에 따라서 이미지 위치 조정해서 출력
	//2. 캐릭터 상태에 따라서 다른 이미지 출력 (승리표시, 패배표시)
	//캐릭터 상태에 따른 이미지를 캐릭터 위치에 출력한다.
}
