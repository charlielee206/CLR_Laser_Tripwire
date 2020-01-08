#include "Keyboard.h" //아두이노 키보드 라이브러리를 사용합니다. 만약 키보드 라이브러리가 없으면 https://github.com/arduino-libraries/Keyboard 에서 다운받으세요. 

void setup() 
{
    Serial.begin(9600); 
    Keyboard.begin();
}

void loop()
{
    Serial.println(analogRead(0)); //트러블슈팅을 위해서 시리얼 모니터에 CdS 값을 띄웁니다.

    /* 제가 테스트할때는 
     - 레이저 들어옴 : 600~999 의 값
     - 레이저 끊김 : 0~20 의 값
     이 나왔기 때문에, 임의로 한계를 걍 400 으로 설정하였습니다. 여러분의 레이저 세기, 주변 밝기 등 여러가지 상황에 따라 이 값을 변경해야 할 수도 있습니다. 
     ....뭐 꼭 그럴 필요는 없는데, 그럴 *수* 도 있어요. 그냥 그렇다고요. 알아두세요.... */ 
     
    if(analogRead(0) <= 400) 
    {
      delay(50);  
      if(analogRead(0) <= 400) //if 문을 2번 사용한건, 레이저 자체의 문제로 인해서 가끔식 레이저가 일시적으로 깜빡거릴때가 있어서 이때 작동되는걸 방지하기 위해서입니다. 필요 없다 생각하시면 빼셔도 됩니다.
      { // 여기에 사람 감지 시 작동되는 코드를 넣으시면 됩니다.
         Serial.println("AAAAAAAA"); // 시리얼. 필요없습니다. 디버깅 용.
         Keyboard.press(KEY_LEFT_ALT);
         delay(1);
         Keyboard.press(KEY_TAB);
         //Keyboard.press(KEY_F4); // <-- F4 입니다. Alt+Tab 대신 Alt+F4 를 원하시는 분들은 Keyboard.press(KEY_TAB); 를 주석처리 하시고,  Keyboard.press(KEY_F4); 주석처리를 삭제하시면 됩니다.
         delay(10);
         Keyboard.releaseAll();
         delay(1000);
      }
    }

}
