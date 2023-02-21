#include <intrinsics.h>
#include <arm_itm.h>

#include "main.h"
#include "waveform.h"

unsigned int iVal = 0, index = 0;

int sine[WAVELENGTH];
int ramp[WAVELENGTH];

void critical_section()
{
  /* Update waveform index */
  ++index;
  if (index == WAVELENGTH) {
    ++iVal;
    index = 0;
  }
}

void update_ITM()
{
  if (index == 0) {
    ITM_EVENT32(1, iVal);
    __no_operation();
  }
  ITM_EVENT32(2, sine[index]);
  ITM_EVENT32(3, ramp[index]);
}

void demo()
{
  makeWave(SINE, sine);
  makeWave(RAMP, ramp);

  while(1)
  {
    critical_section();
    update_ITM();

    /* Delay */
    while (uwTick % 4 != 0);
  }
}