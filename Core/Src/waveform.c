#include <math.h>
#include <stdint.h>

#include "waveform.h"

/**
  * @brief  Updates the global waveform according to the selected type
  */
void makeWave(wave_t type, int *destination)
{
  switch (type)
  {
  case SINE:
    for (int i = 0; i < WAVELENGTH; i++)
    {
      float val = sinf(2 * PI * i / WAVELENGTH);
      destination[i] = (uint16_t)((val + 1) * 2048);
    }
    break;

  case SQUARE:
    for(int i = 0; i < (WAVELENGTH / 2); i++)
    {
      destination[i] = 4095;
    }
    for(int i = (WAVELENGTH / 2); i < WAVELENGTH; i++)
    {
      destination[i] = 0;
    }
    break;

  case RAMP:
    for (int i = 0; i < WAVELENGTH; i++)
    {
      destination[i] = (i * 4095) / WAVELENGTH;
    }
    break;

  case TRIANGLE:
    for (int i = 0; i < (WAVELENGTH / 2); i++)
    {
      destination[i] = (i * 4095) / (WAVELENGTH / 2);
    }
    for (int i = (WAVELENGTH / 2); i < WAVELENGTH; i++)
    {
      destination[i] = 4095 - (((i - (WAVELENGTH / 2)) * 4095) / (WAVELENGTH / 2));
    }
    break;

  case DC:
  default:
    break;
  }
}
