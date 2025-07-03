import os
import time
import mysql.connector

mydb = mysql.connector.connect(
    host='localhost',
    user='root',
    database='mytestdb',
    password='1234'
)
mycursor = mydb.cursor()

class User:
    def __init__(self):
        self.login = None
        self.password = None
        self.welcome()

    def welcome(self):
        print('choose one the of options\n 1 - register\n 2 - log in\n 3 - exit :) ')
        choice = input(str('ENTER: '))

        if choice == '1':
            print('WELCOME to Registration page!')
            self.register()
        elif choice == '2':
            self.log_in()
        elif choice == 'exit':
            print('goodbuy :)')
        else:
            os.system('cls')
            print('\nno no no \nnot so fast:) \nwait', end='')
            time.sleep(0.8)
            print('.', end='')
            time.sleep(0.8)
            print('.', end='')
            time.sleep(0.8)
            print('.')
            time.sleep(1)
            self.welcome()

    def register(self):
        os.system('cls')

        self.login = input('ENTER YOUR LOGIN: ').strip()
        login = self.login

        mycursor.execute("SELECT login FROM user WHERE login = %s", (login,))

        data = mycursor.fetchall()
        if len(data) != 0:
            os.system('cls')
            print('this login already used!')

            self.register()
        else:
            self.password = input('ENTER YOU PASSWORD: ').strip()

        passwd = self.password

        sql = "INSERT INTO user (login, passwd) VALUES (%s, %s)"
        val = (login, passwd)
        mycursor.execute(sql, val)
        mydb.commit()

        print('please wait', end=' ')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.')
        time.sleep(1)
        print('WELCOME TO WEB!')

    def log_in(self):
        login2 = input('ENTER YOUR LOGIN: ')
        mycursor.execute("SELECT login FROM user WHERE login = %s", (login2,))
        data = mycursor.fetchall()

        if len(data) == 0:
            os.system('cls')
            print('this login does not exist or incorrect ! please try again:')
            self.re_write_login()

        password = input('ENTER YOUR PASSWORD: ')
        mycursor.execute("SELECT passwd FROM user WHERE passwd = %s", (password,))
        data = mycursor.fetchall()
        if len(data) == 0:
            os.system('cls')
            print('passowrd incorrect please try again')
            self.log_in()

        sql = "INSERT INTO user (login, passwd) VALUES (%s, %s)"
        val = (login2, password)
        mycursor.execute(sql, val)
        mydb.commit()

        print('please wait', end=' ')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.')
        time.sleep(1)
        print(f'WELCOME BACK {login2}!')
        self.options_log_in()

    def options_log_in(self):
        print('OPTIONS:')
        print('1 - log out')
        print('2 - delete account')
        choice = str(input('please choose on of the options: '))

        if choice == '1':
            self.log_out()
        elif choice == '2':
            self.delete_account()
        else:
            print('choose on of the given options')
            self.options_log_in()

    def re_write_login(self):
        print('1 - login \n2 - register')
        choice = str(input('please choose on of the options: '))

        if choice == '1':
            self.login()
        elif choice == '2':
            print('welcome new user!')
            self.register()
        else:
            print('WRONG!')
            print('please choose one of the given options!')
            self.re_write_login()

    def log_out(self):
        print('please wait', end=' ')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.')
        time.sleep(1)
        print('WELCOME to Registration page')
        self.register()

    def delete_account(self):
        password = input('ENTER YOUR PASSWORD: ')
        mycursor.execute("SELECT passwd FROM user WHERE passwd = %s", (password,))
        data = mycursor.fetchall()
        if len(data) == 0:
            print('incorrect')
            print('ENTER again!')
            self.delete_account()
        print('please wait', end=' ')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.', end='')
        time.sleep(0.8)
        print('.')
        time.sleep(1)
        print('Are you sure!')
        print('account will be deleted completely!')
        print('1 - I agree')
        print('2 - no')
        choice = str(input())
        if choice == '1':
            mycursor.execute("DELETE FROM user WHERE login = %s", (self.login,))
            mydb.commit()
            print('please wait', end=' ')
            time.sleep(0.8)
            print('.', end='')
            time.sleep(0.8)
            print('.', end='')
            time.sleep(0.8)
            print('.')
            time.sleep(1)
            print('TAMOM !!!')
        else:
            print('Endi nma !!!')


person = User




person = Ahmadjon 
// bissmila rahmon raxim