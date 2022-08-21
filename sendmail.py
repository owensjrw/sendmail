import sys
import smtplib

def sendemail(from_addr, to_addr_list, cc_addr_list,
              subject, message,
              login, password,
              smtpserver):
    message = message = f"""From: {from_addr}
To: {','.join(to_addr_list)}
Cc: {','.join(cc_addr_list)}
Subject: {subject}

{message}"""

    server = smtplib.SMTP(smtpserver)
    server.ehlo()
    server.starttls()
    server.login(login,password)
    problems = server.sendmail(from_addr, to_addr_list, message)
    server.quit()
    return problems

if __name__ == '__main__':
    globals()[sys.argv[1]](*sys.argv[2:10])
