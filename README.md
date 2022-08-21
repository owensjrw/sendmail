# SENDMAIL

This is my homebrewed solution (with some help from great communities on discord and hexchat) for producing a mass text to individuals with the same message.

How it works.

1. Need a list of contacts formated in one of two ways\
  a. 10digitnumber@sms.gateway\
  b. contact name \<10digitnumber@sms.gateway\>\
there should be no return after the last contact.

compile the sendemailwithpy.c using your c compiler and your favorite switches or 

gcc -g -Wall sendemailwithpy.c -o sendemail

this will create a "shared library" executable file which you can run with ./sendemail

I have also added a makefile for a simple make command however it will create a "shared library" named sendmailwithpy

All three files must be in the same folder.

I have tested this only on:\
description: Desktop Computer\
    product: Inspiron 3847 (0622)\
     vendor: Dell Inc.\
      width: 64 bits

Running:\
Linux 5.4.0-124-generic \
      #140-Ubuntu\
      x86_64\
      GNU/Linux\

SMS Gateways:
|Mobile carrier 	 |SMS gateway domain 	     |MMS gateway domain       |
|:-----------------|:------------------------|:------------------------|
|Alltel 	         |sms.alltelwireless.com 	 |mms.alltelwireless.com   |
|AT&T 	           |txt.att.net 	           |mms.att.net              |
|Boost Mobile  	   |sms.myboostmobile.com 	 |myboostmobile.com        |
|Cricket Wireless  |mms.cricketwireless.com  |mms.cricketwireless.com  |
|Google Fi 		     |                         |msg.fi.google.com        |
|MetroPCS 	       |mymetropcs.com 	         |mymetropcs.com           |
|Republic Wireless |text.republicwireless.com|                         |	
|Sprint 	         |messaging.sprintpcs.com  |pm.sprint.com            |
|T-Mobile 	       |tmomail.net 	           |tmomail.net              |
|U.S. Cellular 	   |email.uscc.net 	         |mms.uscc.net             |
|Verizon Wireless	 |vtext.com 	             |vzwpix.com               |
|Virgin Mobile     |vmobl.com                |vmpix.com                |
