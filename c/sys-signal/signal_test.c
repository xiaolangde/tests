  #include   <signal.h>   
  #include   <stdio.h>   
  #include   <windows.h>

/*  void   sig_int(int   sig)   
  {   
  if(sig==SIGINT)
   {
	printf("Catch   a   termination   single.\n");   
	}
	else
	  {
		printf("it is not a Ctrl+C.\n");
	  }

  }   
    
  int   main()   
  {   
	  int a =0x400;
	  typedef void (*ff)();

  printf("&sig_int:%x\nsig_int:%x\nreturn:%x\n",&sig_int,sig_int,signal(SIGSEGV,   &sig_int));
  (*(ff)a)();
  Sleep(10*1000);   
    
  return   0;   
  }   */
  void sig_callback1(int sig)
  {
	printf("sig_callback1 is called\n");
  }
  void sig_callback2(int sig)
  {
	printf("sig_callback2 is called\n");
	//exit(0);
  }
  int main()
  {
	signal(SIGINT,sig_callback1);
	printf("sig_callback1 is registered for SIGINT\n");
	printf("sleep 3s\n");
	Sleep(3*1000);
	printf("awaked\n");
	signal(SIGINT,sig_callback2)(SIGINT);
	printf("sig_callback2 is registered for SIGINT\n");
	printf("sleep10s\n");
	Sleep(10*1000);
	printf("awaked\n");
	return 0;
  }
