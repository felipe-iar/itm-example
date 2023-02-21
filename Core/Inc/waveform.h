#ifndef _WAVEFORM_H_
#define _WAVEFORM_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define PI               (3.1415927f)
#define WAVELENGTH       (5760)

typedef enum {
  SINE,
  SQUARE,
  RAMP,
  TRIANGLE,
  DC,
} wave_t;

typedef unsigned int vol_t;

void makeWave(wave_t, int *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WAVEFORM_H_ */