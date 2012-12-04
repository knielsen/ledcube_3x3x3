#include <util/delay.h>
#include <arduino/pins.h>

#define DELAY 200.0

#if 1
#define delay(n) _delay_us(n)
#else
#define delay(n) _delay_ms(n)
#endif

#if 0
static const uint8_t imageTab[5][10] = {
	{ 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 0b000, 0b111, 0b000, 108 }, 
	{ 0b100, 0b010, 0b001, 0b100, 0b010, 0b001, 0b100, 0b010, 0b001, 108 }, 
	{ 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 108 }, 
	{ 0b001, 0b010, 0b100, 0b001, 0b010, 0b100, 0b001, 0b010, 0b100, 108 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
#else
#if 0
static const uint8_t imageTab[][10] = {
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
#else
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
#endif
#endif

static void
layer_set(const uint8_t *layer)
{
	uint8_t line = layer[0];

	if (line & 1) pin2_low();  else pin2_high();
	if (line & 2) pin3_low();  else pin3_high();
	if (line & 4) pin4_low();  else pin4_high();

	line = layer[1];

	if (line & 1) pin5_low();  else pin5_high();
	if (line & 2) pin6_low();  else pin6_high();
	if (line & 4) pin7_low();  else pin7_high();

	line = layer[2];

	if (line & 1) pin8_low();  else pin8_high();
	if (line & 2) pin9_low();  else pin9_high();
	if (line & 4) pin10_low(); else pin10_high();
}

static void
cycle(const uint8_t setup[9])
{
	layer_set(&setup[0]);
	pin11_high();
	delay(DELAY);
	pin11_low();

	layer_set(&setup[3]);
	pin12_high();
	delay(DELAY);
	pin12_low();

	layer_set(&setup[6]);
	pin13_high();
	delay(DELAY);
	pin13_low();
}

int
main()
{
	pin2_mode_output();
	pin3_mode_output();
	pin4_mode_output();
	pin5_mode_output();
	pin6_mode_output();
	pin7_mode_output();
	pin8_mode_output();
	pin9_mode_output();
	pin10_mode_output();

	pin11_mode_output();
	pin12_mode_output();
	pin13_mode_output();
	

	pin2_low();
	pin3_low();
	pin4_low();
	pin5_low();
	pin6_low();
	pin7_low();
	pin8_low();
	pin9_low();
	pin10_low();

	pin11_low();
	pin12_low();
	pin13_low();

	while (1) {
		const uint8_t *frame;

		for (frame = imageTab[0]; frame[9]; frame += 10) {
			uint8_t i;

			for (i = 200; i; i--)
				cycle(frame);
		}
	}

	return 0;
}
