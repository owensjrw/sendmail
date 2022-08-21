#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void resetGetLine(char *inputBuffer, size_t *lenvar) {
  inputBuffer = NULL;
  lenvar = 0;
}

static void dropNewLine(char *getLineBuffer, ssize_t read){
  getLineBuffer[read - 1] = '\0';
}

int main(void) {
  FILE *contactsFile;

  char *from           = "user@domain",
       *to,
       *cc             = "",
       *subject,
       *message,
       *smtplogin      = "smtp login",
       *smtppassword   = "smtp password in plaintext",
       *smtphostport   = "smtp server:port",
       *command        = "python3 sendmail.py sendemail",
       *sendmessage;

  size_t len = 0;
  ssize_t read;

  if ((contactsFile = fopen("contacts.txt", "r")) == NULL) {
    fprintf(stderr, "Error - Unable to open contacts.txt");
    exit(-1);
  }

  puts("Please enter the Subject:");
  if ((read = getline(&subject, &len, stdin)) != -1) {
    dropNewLine(subject, read);
    len = 0;
  } else {
    fprintf(stderr, "Error - Unable to write Subject.");
    exit(-2);
  }

  puts("Please enter the message:");
  if ((read = getline(&message, &len, stdin)) != -1) {
    dropNewLine(message, read);
    len = 0;
  } else {
    fprintf(stderr, "Error - Unable to write Message.");
    exit(-3);
  }

  while ((read = getline(&to, &len, contactsFile)) != -1) {
    dropNewLine(to, read);
    size_t msglen = strlen(from)           +
                    strlen(to)             +
                    strlen(cc)             +
                    strlen(subject)        +
                    strlen(message)        +
                    strlen(smtplogin)      +
                    strlen(smtppassword)   +
                    strlen(smtphostport)   +
                    strlen(command);

     sendmessage = malloc(msglen + 26);

     sprintf(sendmessage, "%s \"%s\" \"%s\" \"%s\" \"%s\" "
                          "\"%s\" \"%s\" \"%s\" \"%s\"\n",
                          command, from, to, cc, subject, message,
                          smtplogin, smtppassword, smtphostport);
     resetGetLine(to, &len);
     resetGetLine(subject, &len);
     resetGetLine(message, &len);
     //printf("%s", sendmessage);
     system(sendmessage);
   }

  return 0;
}
