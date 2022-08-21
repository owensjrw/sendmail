#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void dropNewLine(char *getLineBuffer, ssize_t read){
  getLineBuffer[read - 1] = '\0';
}

int main(void) {
  FILE *contactsFile;

  char *from           = "from",
       *to             = NULL,
       *cc             = "cc",
       *subject        = NULL,
       *message        = NULL,
       *smtplogin      = "smtplogin",
       *smtppassword   = "smtppassword_plaintext",
       *smtphostport   = "server:port",
       *command        = "python3 sendmail.py sendemail",
       *sendmessage    = NULL;

  size_t len = 0;
  ssize_t read = 0;

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
    asprintf(&sendmessage, "%s \"%s\" \"%s\" \"%s\" \"%s\" "
                           "\"%s\" \"%s\" \"%s\" \"%s\"\n",
                           command, from, to, cc, subject, message,
                           smtplogin, smtppassword, smtphostport);

    system(sendmessage);

    free(to);
    len = 0;
    free(sendmessage);

  }

  fclose(contactsFile);
  free(to);
  free(subject);
  free(message);

  return EXIT_SUCCESS;
}
