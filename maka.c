#include <SwitchControlLibrary.h>

void setup() {
  // put your setup code here, to run once:
  SwitchControlLibrary(); // 初期化

  // 起動時のAボタン連打
  for (int i=0; i <= 12; i++){
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(800);
  }
}

int cnt = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (cnt >= 10) {
    koueki();
    position_init();
    talk2neko();
    exit(0);
  }

  if (cnt == 0) {
    position_init();
  }

  walk2minoto();
  talk();
  if (cnt % 2 == 0) {
    item();
  }
  go2quest();
  bakuha();
  finish();
  cnt += 1;
}

// 初期値へ移動する関数 カムラの里
void position_init() {
  //　初期位置に行く処理
  SwitchControlLibrary().pressButton(Button::MINUS);
  SwitchControlLibrary().sendReport();
  delay(1000);
  SwitchControlLibrary().releaseButton(Button::MINUS);
  SwitchControlLibrary().sendReport(); 

  delay(600); // 1秒待機

  // すべて受け取るへ移動
  SwitchControlLibrary().moveHat(Hat::UP);
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

  delay(2000);
  return;
}


// ミノトへ移動する関数
void walk2minoto() {

  // 走るためにRを押す
  SwitchControlLibrary().pressButton(Button::R);
  SwitchControlLibrary().sendReport();

  // 左斜移動
  SwitchControlLibrary().moveLeftStick(0, Stick::MIN); // 左スティックは上
  SwitchControlLibrary().sendReport();

  delay(1200);

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  // 走るのをやめる
  SwitchControlLibrary().releaseButton(Button::R);
  SwitchControlLibrary().sendReport();

  delay(500);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();

  return;
}

void talk() {
  for (int i=0; i <= 4; i++){
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(1000);
  }  

  delay(1500);
}

void item() {

  // 走るためにRを押す
  SwitchControlLibrary().pressButton(Button::R);
  SwitchControlLibrary().sendReport();

  // 上移動
  SwitchControlLibrary().moveLeftStick(160, Stick::MIN); // 左スティックは上
  SwitchControlLibrary().sendReport();

  delay(1800);

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  // 走るのをやめる
  SwitchControlLibrary().releaseButton(Button::R);
  SwitchControlLibrary().sendReport();

  // アイテムボックスを開く
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1500);

  // ハンターマイセットを選択
  SwitchControlLibrary().moveHat(Hat::UP);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL);
  SwitchControlLibrary().sendReport();
  delay(100);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // マカ錬金セットを選択
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(500);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(2000);


  SwitchControlLibrary().pressButton(Button::B);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::B);
  SwitchControlLibrary().sendReport();
  delay(2000);

  SwitchControlLibrary().pressButton(Button::B);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::B);
  SwitchControlLibrary().sendReport();
  delay(2000);

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

  // 出発ロード時間
  delay(27000);

  return;
}


void bakuha() {
  // 爆弾
  SwitchControlLibrary().pressButton(Button::Y);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::Y);
  SwitchControlLibrary().sendReport();
  delay(2000);

  // ZRで起爆
  SwitchControlLibrary().pressButton(Button::ZR);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::ZR);
  SwitchControlLibrary().sendReport();
  delay(14000);

  return;
}

void finish() {
  for (int i=0; i <= 5; i++){
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    delay(1000);
  }

  delay(20000); //22秒待機
}

void koueki() {
  //　初期位置に行く処理
  SwitchControlLibrary().pressButton(Button::MINUS);
  SwitchControlLibrary().sendReport();
  delay(1000);
  SwitchControlLibrary().releaseButton(Button::MINUS);
  SwitchControlLibrary().sendReport(); 

  delay(600); // 1秒待機

  SwitchControlLibrary().moveHat(Hat::UP);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  SwitchControlLibrary().moveHat(Hat::UP);
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

  delay(2000);

  SwitchControlLibrary().moveLeftStick(255, Stick::MIN); // 左スティックは上
  SwitchControlLibrary().sendReport();

  delay(500);

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  // 話しかける
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // 交易船の選択
  SwitchControlLibrary().moveHat(Hat::DOWN);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  SwitchControlLibrary().moveHat(Hat::DOWN);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // アイテムを増やすを選択
  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  // 受け取りを選択
  SwitchControlLibrary().moveHat(Hat::UP);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);


  // アイテムをすべて受け取る
  SwitchControlLibrary().moveHat(Hat::UP);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().moveHat(Hat::NEUTRAL); // ハットは上
  SwitchControlLibrary().sendReport();
  delay(100);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  for (int i=0; i <= 6; i++){
    SwitchControlLibrary().pressButton(Button::B);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().releaseButton(Button::B);
    SwitchControlLibrary().sendReport();
    delay(1000);
  }
  return;
}

void talk2neko() {

  // 走るためにRを押す
  SwitchControlLibrary().pressButton(Button::R);
  SwitchControlLibrary().sendReport();

  // 上移動
  SwitchControlLibrary().moveLeftStick(0, 150); // 左スティックは上
  SwitchControlLibrary().sendReport();

  delay(1700);

  SwitchControlLibrary().moveLeftStick(128, 128); // 左スティックはニュートラル
  SwitchControlLibrary().sendReport();

  // 走るのをやめる
  SwitchControlLibrary().releaseButton(Button::R);
  SwitchControlLibrary().sendReport();


  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(2000);

  for (int i=0; i <= 1; i++){
    SwitchControlLibrary().moveHat(Hat::DOWN);
    SwitchControlLibrary().sendReport();
    delay(100);
    SwitchControlLibrary().moveHat(Hat::NEUTRAL);
    SwitchControlLibrary().sendReport();
    delay(100);
  }

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);

  SwitchControlLibrary().pressButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().sendReport();
  delay(1000);
}
