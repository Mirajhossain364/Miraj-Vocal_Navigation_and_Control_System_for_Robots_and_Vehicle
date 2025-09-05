String voice;

#define lf 5   
#define lb 6   
#define ls 7      
                      


#define rf 10
#define rb 11
#define rs 12

int pwm = 255;
int s;
                    
void setup() 
{
  Serial.begin(9600);
  

 pinMode (lf , OUTPUT);
 pinMode (lb , OUTPUT);
 pinMode (rf , OUTPUT);
 pinMode (rb , OUTPUT);
 pinMode (ls , OUTPUT);
 pinMode (rs , OUTPUT);


 void stop();
}

void loop() 
{
  Serial.println(pwm);

  analogWrite(ls,pwm);
  analogWrite(rs,pwm);

  while (Serial.available()) 
  {
    delay(10);
    char c = Serial.read();
    voice += c;
  }

  if (voice.length() > 0) 
  {
    //Serial.println(voice);

    if(voice=="forward") 
    {
      forward() ;
      delay(2000);
      stop();
    }

    else if(voice=="backward") 
    {
      backward();
      delay(2000);
      stop();
    }
    else if(voice=="right") 
    {
      right();
      delay(500);
      stop();
    }
    else if(voice=="left") 
    {
      left();
      delay(500);
      stop();
    }
    else if(voice=="forward right") 
    {
      forwardright();
      delay(500);
      stop();
    }
    else if(voice=="forward left") 
    {
      forwardleft();
      delay(500);
      stop();
    }
    else if(voice=="backward right") 
    {
      backwardright();
      delay(500);
      stop();
    }
    else if(voice=="backward left") 
    {
      backwardleft();
      delay(500);
      stop();
    }
    else if(voice=="stop" || voice == "ok") stop();
    else if (voice.startsWith("motion")) 
    {
      pwm = speed(voice); 
    }
    else stop();
  }
  voice = "";
}


void forward()
{
  digitalWrite (lf , HIGH);
  digitalWrite (lb , LOW);
  
  
  digitalWrite (rf , HIGH);
  digitalWrite (rb , LOW);
  
  
}


void backward()
{
  digitalWrite (lf , LOW);
  digitalWrite (lb , HIGH);

  
  
  digitalWrite (rf , LOW);
  digitalWrite (rb , HIGH);
    

  
}

void right()
{
  digitalWrite (lf , HIGH);
  digitalWrite (lb , LOW);

  
  
  digitalWrite (rf , LOW);
  digitalWrite (rb , HIGH);
  
  
}


void left ()
{
  digitalWrite (lf , LOW);
  digitalWrite (lb , HIGH);

  


  
  digitalWrite (rf , HIGH);
  digitalWrite (rb , LOW);
   
  
}

void forwardright()
{
  digitalWrite (lf , HIGH);
  digitalWrite (lb , LOW);
  
  
  digitalWrite (rf , LOW);
  digitalWrite (rb , LOW);
  
  
}

void forwardleft()
{
  digitalWrite (lf , LOW);
  digitalWrite (lb , LOW);

  
  
  digitalWrite (rf , HIGH);
  digitalWrite (rb , LOW);
  
  
}

void backwardright()
{
  digitalWrite (lf , LOW);
  digitalWrite (lb , HIGH);

  
  
  digitalWrite (rf , LOW);
  digitalWrite (rb , LOW); 

  
}


void backwardleft ()
{
  digitalWrite (lf , LOW);
  digitalWrite (lb , LOW);

  

  
  digitalWrite (rf , LOW);
  digitalWrite (rb , HIGH);
    
  
}

void stop()
{
  digitalWrite (lf , LOW);
  digitalWrite (lb , LOW);
  
  digitalWrite (rf , LOW);
  digitalWrite (rb , LOW);
  
  
}
int speed(String voice)
 {
  
  int s =255;

  

  if(voice=="motion 10") s = 255-(11 *1);

  else if(voice=="motion 9") s = 255-(11 *2);

  else if(voice=="motion 8") s = 255-(11 *3);

  else if(voice=="motion 7") s = 255-(11 *4);

  else if(voice=="motion 6") s = 255-(11 *5);

  else if(voice=="motion 5") s = 255-(11 *6);

  else if(voice=="motion 4") s = 255-(11 *7);

  else if(voice=="motion 3") s = 255-(11 *8);

  else if(voice=="motion 2") s = 255-(11 *9);

  else if(voice=="motion 1") s = 255-(11 *10);


  return s;
 }




