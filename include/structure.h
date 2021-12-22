/*
 * Base structure for every task function. No final desicion but still.
 *
 * @author e3stpavel
 * 
 * @param code Task function's execution code (should be from 0), also need to introduce same codes that everyone can use
 * For instance, code 0 means successful execution
 * @param status Taks function's execution status, the brief description of execution code 
 * @param extra For now is optional. I use direction. Meaning in which side we stopped our func.
 * @returns tsk
 */ 

struct tsk
{
  /* structure data */
  unsigned short code;
  String status;
  char end_direction;
  // ... extra
  // ps struct fields can be ignored if you dont want to return them in your func
};
