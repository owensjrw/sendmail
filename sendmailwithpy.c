#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Gets rid of new line charater written by getline()
static void dropNewLine(char *getLineBuffer, ssize_t read){
  getLineBuffer[read - 1] = '\0';
}

int main(void) {
  FILE *contactsFile;

  //Set from, cc, smtplogin, smtppassword, and smptphostport variable prior to compiling
  char *from           = "send_from@domain",
       *to,
       *cc             = "",
       *subject,
       *message,
       *smtplogin      = "smtp user login",
       *smtppassword   = "smtp user password plaintext",
       *smtphostport   = "smtp server:port",
       *command        = "python3 sendmail.py sendemail",
       *sendmessage;

  size_t len = 0;
  ssize_t read;

  //Open contacts list
  if ((contactsFile = fopen("contacts.txt", "r")) == NULL) {
    fprintf(stderr, "Error - Unable to open contacts.txt");
    exit(-1);
  }

  //Gets subject and message will be the same for all recipents in contact list
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

  //Writes header and message to be sent to SMS gateway via SMTP for each contact
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
     to = NULL;
     len = 0;
     //Runs Python function sendemail() in sendmail.py
     system(sendmessage);
   }

   //Clean heap memory
   fclose(contactsFile);
   free(to);
   free(subject);
   free(message);
   free(sendmessage);

  EXIT_SUCCESS; //Not required but nice to have.
}
