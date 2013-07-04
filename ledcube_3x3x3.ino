#include <util/delay.h>

#define DELAY 200.0

#define delay(n) _delay_us(n)

static const uint8_t imageTab[][10] = {
	{ 0b111, 0b111, 0b111, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b111, 0b111, 0b111, 0b000, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b111, 0b111, 0b111, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 108 }, 
	{ 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 108 }, 
	{ 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 108 }, 
	{ 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 108 }, 
	{ 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 108 }, 
	{ 0b010, 0b010, 0b010, 0b000, 0b010, 0b010, 0b010, 0b010, 0b010, 108 }, 
	{ 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 108 }, 
	{ 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 108 }, 
	{ 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b111, 0b111, 0b111, 108 }, 
	{ 0b000, 0b000, 0b000, 0b111, 0b111, 0b111, 0b000, 0b000, 0b000, 108 }, 
	{ 0b111, 0b111, 0b111, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

static const uint8_t imageTab2[5][10] = {
	{ 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 108 }, 
	{ 0b100, 0b010, 0b001, 0b100, 0b010, 0b001, 0b100, 0b010, 0b001, 108 }, 
	{ 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 108 }, 
	{ 0b001, 0b010, 0b100, 0b001, 0b010, 0b100, 0b001, 0b010, 0b100, 108 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

static const uint8_t imageTab3[][10] = {
	{ 0b000, 0b000, 0b100, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 108 }, 
	{ 0b000, 0b110, 0b110, 0b000, 0b110, 0b110, 0b000, 0b000, 0b000, 108 }, 
	{ 0b111, 0b101, 0b111, 0b111, 0b101, 0b111, 0b111, 0b101, 0b111, 108 }, 
	{ 0b000, 0b000, 0b000, 0b011, 0b011, 0b000, 0b011, 0b011, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b001, 0b000, 0b000, 108 }, 
	{ 0b000, 0b000, 0b000, 0b011, 0b011, 0b000, 0b011, 0b011, 0b000, 108 }, 
	{ 0b111, 0b101, 0b111, 0b111, 0b101, 0b111, 0b111, 0b101, 0b111, 108 }, 
	{ 0b000, 0b110, 0b110, 0b000, 0b110, 0b110, 0b000, 0b000, 0b000, 108 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

void
layer_set(const uint8_t *layer)
{
	uint8_t line = layer[0];

	if (line & 1) digitalWrite(2, LOW);  else digitalWrite(2, HIGH);
	if (line & 2) digitalWrite(3, LOW);  else digitalWrite(3, HIGH);
	if (line & 4) digitalWrite(4, LOW);  else digitalWrite(4, HIGH);

	line = layer[1];

	if (line & 1) digitalWrite(5, LOW);  else digitalWrite(5, HIGH);
	if (line & 2) digitalWrite(6, LOW);  else digitalWrite(6, HIGH);
	if (line & 4) digitalWrite(7, LOW);  else digitalWrite(7, HIGH);

	line = layer[2];

	if (line & 1) digitalWrite(8, LOW);  else digitalWrite(8, HIGH);
	if (line & 2) digitalWrite(9, LOW);  else digitalWrite(9, HIGH);
	if (line & 4) digitalWrite(10, LOW); else digitalWrite(10, HIGH);
}

void
cycle(const uint8_t setup[9])
{
	layer_set(&setup[0]);
	digitalWrite(11, HIGH);
	delay(DELAY);
	digitalWrite(11, LOW);

	layer_set(&setup[3]);
	digitalWrite(12, HIGH);
	delay(DELAY);
	digitalWrite(12, LOW);

	layer_set(&setup[6]);
	digitalWrite(13, HIGH);
	delay(DELAY);
	digitalWrite(13, LOW);
}

void
setup()
{
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);

	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	

	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, LOW);
	digitalWrite(6, LOW);
	digitalWrite(7, LOW);
	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	digitalWrite(10, LOW);

	digitalWrite(11, LOW);
	digitalWrite(12, LOW);
	digitalWrite(13, LOW);
}

void
loop()
{
        const uint8_t *frame;

        for (frame = imageTab[0]; frame[9]; frame += 10) {
                uint8_t i;

                for (i = 200; i; i--)
                        cycle(frame);
        }

}
