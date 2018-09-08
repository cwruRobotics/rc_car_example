#define PIN 	7
#define LAG 	10

// enum COMMANDS = {
// 	FORWARD 		= 10,
// 	TURBO 			= 22,
// 	FORWARD_LEFT 	= 28,
// 	FORWARD_RIGHT 	= 34,
// 	BACKWARD 		= 40,
// 	BACK_LEFT 		= 52,
// 	BACK_RIGHT 		= 46
// };

void send_start_cmd(void);
void send_cmd(uint8_t);
void send_end_cmd(void);

void setup(){

}

void loop(){
	for(uint8_t i = 0; i< 100; i++){
		send_cmd(10); 	// drive forward
		send_end_cmd();
	}
	
	for(uint8_t i = 0; i< 100; i++){
		send_end_cmd();
	}

	for(uint8_t i = 0; i< 100; i++){
		send_cmd(10); 	// drive forward
		send_end_cmd();
		send_end_cmd();
	}
	
	for(uint8_t i = 0; i< 100; i++){
		send_end_cmd();
	}
	
}

void send_end_cmd(){
	send_cmd(4);
}

void send_start_cmd(){
	// digitalWrite(PIN, LOW);

	digitalWrite(PIN, HIGH);
	delayMicroseconds(1500 - LAG);
	digitalWrite(PIN, LOW);
	delayMicroseconds(500 - LAG);

	digitalWrite(PIN, HIGH);
	delayMicroseconds(1500 - LAG);
	digitalWrite(PIN, LOW);
	delayMicroseconds(500 - LAG);

	digitalWrite(PIN, HIGH);
	delayMicroseconds(1500 - LAG);
	digitalWrite(PIN, LOW);
	delayMicroseconds(500 - LAG);

	digitalWrite(PIN, HIGH);
	delayMicroseconds(1500 - LAG);
	digitalWrite(PIN, LOW);
	delayMicroseconds(500 - LAG);
}

void send_cmd(uint8_t num){
	send_start_cmd();
	for(uint8_t i = 0; i<num ; i++){
		digitalWrite(PIN, HIGH);
		delayMicroseconds(500 - LAG);
		digitalWrite(PIN, LOW);
		delayMicroseconds(500 - LAG);
	}
}
