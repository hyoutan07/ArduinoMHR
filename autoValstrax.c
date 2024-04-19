#include <SwitchControlLibrary.h>

void setup() {
  // put your setup code here, to run once:
  SwitchControlLibrary(); // 初期化

  // 起動時のAボタン連打
  for (int i=0; i <= 7; i++){
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(1000);
  }

}


void loop() {
  // put your main code here, to run repeatedly:
  position_init();
  walk2talk();
  talk();
  eat_dango();
  go2quest();

  battle();

  recieve_reward();
  delay(10000); //10秒待機
}

// 初期値へ移動する関数
void position_init() {
  //　初期位置に行く処理
  SwitchControlLibrary().pressButton(Button::MINUS);
  SwitchControlLibrary().sendReport();
  delay(1000);
  SwitchControlLibrary().releaseButton(Button::MINUS);
  SwitchControlLibrary().sendReport(); 

  delay(1000); // 1秒待機

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(50);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport(); 

  delay(100);
  return;
}

// チッチェ姫まで歩く関数
void walk2talk() {
  SwitchControlLibrary().moveLeftStick(Stick::MAX, Stick::NEUTRAL); // 左スティックは右
  SwitchControlLibrary().sendReport();

  delay(1400);

  SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::MIN); // 左スティックは上
  SwitchControlLibrary().sendReport();
  
  delay(1000);

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  delay(100);
  return;
}


// チッチェ姫からクエストを受ける関数
void talk() {

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(50);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();

  delay(3000); // 3秒待機

  // for (int i=0; i <= 7; i++){
  //   SwitchControlLibrary().moveHat(Hat::UP);
  //   SwitchControlLibrary().sendReport();
  //   delay(100);
  //   SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  //   SwitchControlLibrary().sendReport();
  //   delay(100);
  // }

  // delay(3000); // 3秒待機

  // クエストの決定
  for (int i=0; i <= 1; i++) {
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(50);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(1000);
  }

  // クエスト選択
  // for (int i=0; i <= 3; i++){
  //   SwitchControlLibrary().moveHat(Hat::DOWN);
  //   SwitchControlLibrary().sendReport();
  //   delay(100);
  //   SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  //   SwitchControlLibrary().sendReport();
  //   delay(100);
  // }

  for (int i=0; i <= 1; i++) {
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(50);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(1000);
  }

  
  delay(3000); // 3秒待機

  // 次のページへ移動   
  SwitchControlLibrary().moveHat(Hat::RIGHT);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  // 盟友ヒノエ決定
  for (int i=0; i <= 1; i++){
    SwitchControlLibrary().moveHat(Hat::DOWN);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
    SwitchControlLibrary().sendReport();
    delay(100);
  }

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(50);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // 盟友ミノト決定 DOWN
  SwitchControlLibrary().moveHat(Hat::DOWN);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(50);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);


  // クエスト受注
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(50);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);


  delay(4000); // 3秒待機
  return;
}

void eat_dango() {
  position_init();

  // 席へ移動
  SwitchControlLibrary().moveLeftStick(Stick::MAX, Stick::NEUTRAL); // 左スティックは右
  SwitchControlLibrary().sendReport();

  delay(5000);

  SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::MAX); // 左スティックは下
  SwitchControlLibrary().sendReport();
  
  delay(780);

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  // 席に座る
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(3000);

  // 食事をするを選択
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // お金で払うを選択
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // いつもの注文を選択
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // 謹製おだんご券を使用
  SwitchControlLibrary().pressButton(Button::X);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::X);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // A連打
  for (int i=0; i <= 2; i++){
    delay(1000);
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
  }

  delay(4000);

   // ムービースキップ
  SwitchControlLibrary().pressButton(Button::B);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::B);
  SwitchControlLibrary().sendReport();

  //ムービー待機時間
  delay(8000);


  return;
}


void go2quest() {
  SwitchControlLibrary().pressButton(Button::ZR);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::ZR);
  SwitchControlLibrary().sendReport();
  delay(1000);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();

  // クエスト開始の待機時間
  delay(40000); //30秒待機

  return;
}

void battle() {
  // delay(30000);

  // ターゲットカメラロックオン
  SwitchControlLibrary().pressButton(Button::RCLICK);
  SwitchControlLibrary().sendReport();
  delay(50);
  SwitchControlLibrary().releaseButton(Button::RCLICK);
  SwitchControlLibrary().sendReport();

  delay(1000);

  // 疾替え
  SwitchControlLibrary().pressButton(Button::ZL);
  SwitchControlLibrary().pressButton(Button::X);
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);
  SwitchControlLibrary().releaseButton(Button::ZL);
  SwitchControlLibrary().releaseButton(Button::X);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();

  delay(1000);

  // 右斜め移動　虹色ひとたまどりをとるため
  SwitchControlLibrary().moveLeftStick(255, Stick::MIN); // 左スティックは上
  SwitchControlLibrary().sendReport();

  delay(1300);

  // 上移動
  SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::MIN); // 左スティックは上
  SwitchControlLibrary().sendReport();

  delay(3000);

  unsigned long t0 = millis() / 1000;
  unsigned long t = millis() / 1000;

  int min = 17;

  // min分間の間攻撃
  while(t-t0 < min * 60) {
    t = millis() / 1000;
    SwitchControlLibrary().pressButton(Button::X);
    SwitchControlLibrary().pressButton(Button::ZR);
    SwitchControlLibrary().sendReport();
    delay(50);
    SwitchControlLibrary().releaseButton(Button::X);
    SwitchControlLibrary().releaseButton(Button::ZR);
    SwitchControlLibrary().sendReport();
    delay(150);
  }

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  delay(10000);

  return ;
}


void recieve_reward() {
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();

  // すべて受け取るへ移動
  SwitchControlLibrary().moveHat(Hat::UP);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  delay(1000);

  // 決定
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();

  delay(5000);

  // 起動時のAボタン連打
  for (int i=0; i <= 5; i++){
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(2000);
  }

  // クエストから帰る待機時間
  delay(30000); //30秒待機
}
