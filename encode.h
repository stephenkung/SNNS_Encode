/*********************************************************
  E:\MyDownloads\Download\Graduate\snns\encode\encode.h
  --------------------------------------------------------
  generated at Sun Apr 15 11:43:29 2018
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern int snns_encode(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} snns_encodeREC = {5,5,snns_encode};
