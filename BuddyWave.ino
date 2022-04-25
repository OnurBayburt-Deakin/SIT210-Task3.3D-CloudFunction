void setup()
{
  pinMode(led, OUTPUT);
  Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);  //Initialise event subscription
}


//Function to blink the LED based on data published by the subscribed event
void myHandler(const char *eventName, const char *data)
{
    int buddy_wave = strcmp(data, "wave");  //If data is "wave" then the LED blinks three times quickly
    int buddy_pat = strcmp(data, "pat");  //If data is "pat" then the LED blinks one time slowly
    
	if (buddy_wave == 0)
	{
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
        delay(100);
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
        delay(100);
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
	}
	else if (buddy_pat == 0)
	{
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
	}
}
