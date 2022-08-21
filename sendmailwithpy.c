#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char *from           = "from@host",
       *to             = "to@smsgateway",
       *cc             = "cc@host",
       *subject        = "Subject",
       *message        = "Message",
       *smtplogin      = "smtp lobin",
       *smtppassword   = "smtp password",
       *smtphostport   = "smtp server:port",
       *command        = "python3 sendmail.py sendemail",
       *sendmessage;

  size_t msglen = strlen(from)           +
                  strlen(to)             +
                  strlen(cc)             +
                  strlen(subject)        +
                  strlen(message)        +
                  strlen(smtplogin)      +
                  strlen(smtppassword)   +
                  strlen(smtphostport)   +
                  strlen(command);

  sendmessage = malloc(msglen + 1);

  sprintf(sendmessage, "%s \"%s\" \"%s\" \"%s\" \"%s\" "
                       "\"%s\" \"%s\" \"%s\" \"%s\"",
                        command, from, to, cc, subject, message,
                        smtplogin, smtppassword, smtphostport);

  system(sendmessage);

  return 0;
}
