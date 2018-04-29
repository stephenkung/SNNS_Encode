/*********************************************************
  E:\MyDownloads\Download\Graduate\snns\encode\encode.c
  --------------------------------------------------------
  generated at Sun Apr 15 11:43:29 2018
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

#include <math.h>

#define Act_Logistic(sum, bias)  ( (sum+bias<10000.0) ? ( 1.0/(1.0 + exp(-sum-bias) ) ) : 0.0 )
#ifndef NULL
#define NULL (void *)0
#endif

typedef struct UT {
          float act;         /* Activation       */
          float Bias;        /* Bias of the Unit */
          int   NoOfSources; /* Number of predecessor units */
   struct UT   **sources; /* predecessor units */
          float *weights; /* weights from predecessor units */
        } UnitType, *pUnit;

  /* Forward Declaration for all unit types */
  static UnitType Units[17];
  /* Sources definition section */
  static pUnit Sources[] =  {
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, 
Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, 
Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, 
Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, 
Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, 

  };

  /* Weigths definition section */
  static float Weights[] =  {
0.012080, 5.065910, -0.000010, -0.013010, -0.081790, 
-0.181770, -0.277100, -0.405210, -0.007410, -4.642830, 
0.131000, 0.189800, 0.242490, 0.276110, 0.370270, 
3.974150, -0.052150, -0.102940, -0.011590, -0.093330, 
0.114500, 0.319650, 0.589170, 9.875360, 0.516360, 
0.058910, 0.117740, 7.770040, 0.144330, 0.011650, 
-0.013850, 0.000100, 10.145810, 2.753270, 0.025080, -0.034910, 
1.536170, 0.045800, 10.053730, 0.041440, 0.015070, 0.012420, 
0.042390, 0.129350, 10.297530, 0.017870, 0.064830, 0.681060, 
0.092840, -0.110570, 9.167570, 0.063820, 0.380920, 0.118490, 
-0.040080, 0.770620, 11.969540, -0.051860, 0.031950, 0.000670, 

  };

  /* unit definition section (see also UnitType) */
  static UnitType Units_real[17] = 
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (Old: 1) */
      0.0, 0.999980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (Old: 2) */
      0.0, 0.999980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (Old: 3) */
      0.0, 0.999980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (Old: 4) */
      0.0, 0.999990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (Old: 5) */
      0.0, 0.999980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (Old: 6) */
      0.0, -4.523100, 5,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (Old: 7) */
      0.0, 1.043570, 5,
       &Sources[5] , 
       &Weights[5] , 
      },
    { /* unit 8 (Old: 8) */
      0.0, -0.293280, 5,
       &Sources[10] , 
       &Weights[10] , 
      },
    { /* unit 9 (Old: 9) */
      0.0, -3.685550, 5,
       &Sources[15] , 
       &Weights[15] , 
      },
    { /* unit 10 (Old: 10) */
      0.0, -9.533490, 5,
       &Sources[20] , 
       &Weights[20] , 
      },
    { /* unit 11 (Old: 11) */
      0.0, -6.764930, 5,
       &Sources[25] , 
       &Weights[25] , 
      },
    { /* unit 12 (Old: 12) */
      0.0, -6.609640, 6,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 13 (Old: 13) */
      0.0, -6.287780, 6,
       &Sources[36] , 
       &Weights[36] , 
      },
    { /* unit 14 (Old: 14) */
      0.0, -6.213990, 6,
       &Sources[42] , 
       &Weights[42] , 
      },
    { /* unit 15 (Old: 15) */
      0.0, -5.384110, 6,
       &Sources[48] , 
       &Weights[48] , 
      },
    { /* unit 16 (Old: 16) */
      0.0, -7.024870, 6,
       &Sources[54] , 
       &Weights[54] , 
      }

  };



int snns_encode(float *in, float *out, int init)
{
  int member, source, ww;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[5] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5}; /* members */

  static pUnit Hidden1[6] = {Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11}; /* members */

  static pUnit Output1[5] = {Units + 12, Units + 13, Units + 14, Units + 15, Units + 16}; /* members */

  static int Output[5] = {12, 13, 14, 15, 16};

  for(ww=0;ww<17;ww++){
  Units[ww]=Units_real[ww];
  }

  for(member = 0; member < 5; member++) {
    Input[member]->act = in[member];
  }

  for (member = 0; member < 6; member++) {
    unit = Hidden1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 5; member++) {
    unit = Output1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for(member = 0; member < 5; member++) {
    out[member] = Units[Output[member]].act;
  }

  return(OK);
}
