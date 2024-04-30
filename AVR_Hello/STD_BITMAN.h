
#define BIT_SET(VAR,BIT_NB)  VAR|=(1<<BIT_NB)
//#define BIT_GET(VAR,BIT_NB)  (VAR&(1<<BIT_NB))>>BIT_NB
#define BIT_GET(VAR,BIT_NB)  (VAR>>BIT_NB)&1

#define BIT_CLEAR(VAR,BIT_NB)  VAR&=~(1<<BIT_NB)

#define BIT_FLIP(VAR,BIT_NB)  VAR^=(1<<BIT_NB)




