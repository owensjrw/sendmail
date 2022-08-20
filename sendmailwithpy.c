#include <stdlib.h>

int main(void)
  char *from           = "someone@host",
       *to             = "sentto@smsgateway",
       *cc             = "",
       *subject        = "Test",
       *message        = "This is test message.",
       *smtplogin      = "smtplogin",
       *smtppassword   = "smtppassword",
       *smtphostport   = "smtpserver:port";


  system("python3 sendmail.py sendemail \""from               "\" \
                                        \""to                 "\" \
                                        \""cc                 "\" \
                                        \""subject            "\" \
                                        \""message            "\" \
                                        \""smtplogin          "\" \
                                        \""smtppassword       "\" \
                                        \""smtphostport       "\"");
  return 0;
}
