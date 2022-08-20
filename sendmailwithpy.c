#include <stdlib.h>

int main(void) {
  system("python3 sendmail.py sendemail \"from@host\"        \
                                        \"to@host\"          \
                                        \"cc@host\"          \
                                        \"subject\"          \
                                        \"message.\"         \
                                        \"smtpLogin\"        \
                                        \"smtpPassword\"     \
                                        \"smtpHost:port\"");
  return 0;
}
