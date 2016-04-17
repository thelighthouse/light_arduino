
void sendString(String string){
  int len=string.length()+1;
  uint8_t tmp[len];
  string.getBytes(tmp,len);
  serial.send(tmp,len-1);
}

  serial.setPacketHandler(&onPacket);
  serial.begin(115200);
  //sendString(START);


// This is our packet callback.
// The buffer is delivered already decoded.
void onPacket(const uint8_t* buffer, size_t size)
{
  
  if(size==0){
    serialMode=true;
    sendString("ok");
    //fill_solid(leds,NUM_LEDS,CHSV(0,255,255));
  } else {
    serialMode=false;


    uint8_t cmd=buffer[0];
    if (cmd==1){
      sleep_mult=buffer[1];
    }
    
    if (cmd==5){
      clut[buffer[1]]=CHSV(buffer[2],buffer[3],buffer[4]);
      sendString("set clut");
    } else { 
      sendString("unknown cmd");
    }
  
    //animate();
  }
  /*
  if(mode==1){
    sendString("full fill");
    fill_solid(leds,NUM_LEDS,CHSV(buffer[1],buffer[2],buffer[3]));
    
    
  } else if(mode==2){
    sendString("gradient fill");
    fill_gradient(leds,NUM_LEDS,CHSV(buffer[1],buffer[2],buffer[3]),CHSV(buffer[4],buffer[5],buffer[6]),LONGEST_HUES);
  } else if(mode==3){
    sendString("repeat pattern");
    
    int num_colors=(size-1)/3;
     for(int i = 0; i < NUM_LEDS; i++) { 
            int color_num=i%num_colors;
            leds[i] = CHSV(buffer[3*color_num+1],buffer[3*color_num+2],buffer[3*color_num+3]); 
        }
        
     
  } else if(mode==4){
    sendString("block fill");
    long start=buffer[1]<<8 | buffer[2];
    long num=buffer[3]<<8 | buffer[4];
    fill_solid(leds+start,num,CHSV(buffer[5],buffer[6],buffer[7]));
  } else { 
    sendString("unknown mode");
  }
  */
  //FastLED.show();
}
