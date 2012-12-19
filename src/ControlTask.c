
typedef struct
{
	int x; // 캐릭터 x좌표
	int y; // 캐릭터 y좌표

	char status;//캐릭터 상태 (승리,패배,보통)
}PlayData;


static
portTASK_FUNCTION(ControlTask, pvParameters )
{
	while (1) {
		setPlayData();
	}
}


void setPlayData()
{
	getKey();

	//1. 현재 받아드려진 키값으로 변경되야할 좌표생성한다.
	//2. 현재 캐릭터 상태에 따라서 변경된 좌표가 적용될시 변경되는 캐릭터상태도 채워준다.

	//생성된 내용들을 PlayData전역변 값을 채워서 최신화시켜준다.
}