Project : Terminal File Explorer
---------------------------------
Aditya Tewari
Mtech CSE,IIITH, 2018201082
(Readme as on 3/9/18)
---------------------------------

###################Assumptions and project restrictions######################### 

1. The directory you open the project will be considered as your ROOT. If you try to go a folder above the root the application will not allow you. Although I've not restricted this in GOTO command in command mode for user convinience.
The Explorer automatically takes your CWD and makes it the root and also handles your Home directory path automatically, this will ease some commands in command mode. Although it can also be made wrt the current working Directory by just changing one line in the module1.cpp (I did this to check the working properly) :)

2. The biggest lag is scrooling is not handled as of now in this project. So if you open a folder with more than 34 file/folders it'll display only the first 34 one's.The user environment will not be disturbed however because of this. 
This also does not bother if you want to run some command mode commands. 
Scrolling and Recycle Bin would've been done if APS assignments were not updated :p

3. The application expects to be open in FULL TERMINAL SIZE. Glitches can be seen if you try to mess with the terminal size :( :(
###############################################################################

There are 2 modes in this application.
You enter in the USER MODE.
You can enter the COMMAND MODE whenever you want. Just press the ' : ' key.
You may retract to USER MODE wheever you press the ESC key....

################################################################################
--------------------------------
	|	|				|	|
	|	|	USER MODE 	|	|
---------------------------------

*** The application opens from the path where you're running the code. It automatically takes the CWD you're working on.

*** Files are listed as displayed in 'ls -l -a' command.

Details included while displaying the files::::: **FILE NAME is displayed first because you can easily Enter the FILE / FOLDER you want**

1.File/Directory name(first as it eases your experience) File/Folder names are sorted :)
2.File/Directory size. Human readable format. B/KB/MB/GB etc...
3.Permissions in order dispalyed in ls-l command in ---rwx--- mode. "d" in first if Directory "-" in first if File
4. User name
5. Group name
7.Last modified time. //because why not!

***********************************************

***Whenever in the user mode Cursor starts from the first Folder/File displayed itself. &&&& Did i mention file/folder names are sorted!!!

#####What happens if i press the keyssss???

1. UP ARROW KEY (((ESC+[+A))) && DOWN ARROW KEY (((ESC+[+B)))

	Pressing the UP arrow Allows the cursor to move up/down or hover to above file names.
	It however restricts the user till the name range of displayed file/folder in directories. (!!!!!!No fooling around!!!!!!)
	Basically you can hover easily in the files/folders. The usage of this will be discussed shortly.

2. ENTER key
	
	It allows you to open the folder/file your cursor is on.

	**Opening Folders. It takes you  to that directory and shows you the content where you want to be.
	It gives you the same functionality.
	More over if you click on ".." it will take you to the Parent....

	**Opening Files. It opens your File in the supported applications in a new window.You may comeback to the terminal for further exploring. If you don't have the application??? No problem it will not display ant errors. It will do nothing if the file cannot run on your system.

3. H or h key 
	
	It takes you to the HOME. Or in specific terms. the path from where the application starts. basically the root wrt the application/.

4. Backspace key 

	It takes you to the parent directory.

	EG: If you're in """/home/TAs/OS/PG-1/TEST KIDS""" and you press BSapce it'll take you to """/home/TAs/OS/PG-1""" 

5. Q or q key

	Its QUIT. Time to  exit the application, clear your terminal and get to a better UBUNTU terminal, where you dont have any limitation tortures like you must have in my application.

6. Right and Left arrow key.

	It behaves just like the Left and right hovering key in Windows.
	Left takes you to the last directory you were in.
	Right tales you to the last parent directory you were in .
	It's easier to understand how this works in the application mode. I encourage you to try it out...


Thats the user mode. 

*********Whenever in User mode, A status bar at the botoom will always Display that you're in user mode. Because Why not??


#############################################################################################################
-------------------------------------
	|	|					|	|
	|	|	COMMAND MODE 	|	|
-------------------------------------

Enter this mode by pressing : key.

It allows you to execute some commands and play with your system...

You may exit anytime whenever you press ESC key. (((It's not Count Dracula's castle...you're allowed to leave)))


**************************************


1. ESC key

	Press this if you want to exit to user mode :( :(
-------------------------------------------------------------------

2. create_file <destination> <file name>

	It allows you to create Files to the path you want. 

	eg. create_file Desktop/OS/TEST abc.txt

	Path is relative to root because it gives more scope for using this system to most extent.

* you dont need to give /home/TA_CONSOLE/DESKTOP....
-------------------------------------------------------------------

3. create_dir <destination> <directory name>


	It allows you to create Directories to the path you want. 

	eg. create_file Desktop/OS/TEST HEY_THERE

	Path is relative to root because it gives more scope for using this system to most extent.

* you dont need to give /home/TA_CONSOLE/DESKTOP...
--------------------------------------------------------------------

some terminology used

CWD  :  /home/TA/Desktop/OS_Assign

ROOT :  /home/TA
------------------------------------------------------------------------

ONE FUN FACT:::: ANy command you execute will change lsiting of the current directory above. ie changes are displayed immedietly!!



whereevr destination is said to be respect top ROOT. IT is just done for the ease of user. I can change it to the applicatoion rooot by canging a line>>>>>>>>>>>
------------------------------------------------------------------------------------------
4. copy <source>(s) <Destination>

	It will copy FILE/DIRECTORIES . Directory copy is done recursively with all the file and folder name intact.

	Eg.copy TEST1 TEST2 text.txt Desktop/HERE/

	It'll copy folder TEST in the cwd to the destination.

	<source> path is CWD
	<destination> wrt ROOT

------------------------------------------------------------------------------------------
5. remove <source> 

	It will delete FILE/DIRECTORIES . Directory delete is done recursively with all the file and folder name intact.

	Eg. remove TEST 

	It'll delete folder TEST in the cwd and display change immedietly.

	<source> path is CWD


------------------------------------------------------------------------------------------
6. move <source>(s) <destination>
	

	It will move FILE/DIRECTORIES . Directory move is done recursively with all the file and folder name intact.

	Eg. move TEST  Desktop/HERE/

	It'll copy folder TEST in the cwd to the destination.

	Eg.move TEST1 TEST2 text.txt Desktop/HERE/

	<source> path is CWD
	<destination> wrt ROOT

------------------------------------------------------------------------------------------
7. rename <old_filename> <new_filename>


	It renames!!! 

	Eg. rename <old_filename> <new_filename>

		both files are in the cwd.

		It displays the change immedietly !!

--------------------------------------------------------------------------------------\
8. snapshot <folder> <dumpfile>​


	It is similar to 'ls -R' command

	Dumpo file name is to be given and it creates it in the folder which user wants to take a snapshot of.

	Eg. snapshot Desktop whyudumpme

---------------------------------------------------------------------------------------

9. goto <destination>

	Goto a destination WRT ROOT. It takes you to the folder, lists all the file/folder and enters you in the USER mode.

-----------------------------------------------------------------------------------------

10. search <file/folder> name

	I am performing search wrt ROOT.

	*************8whereevr destination is said to be respect top ROOT. IT is just done for the ease of user. I can change it to the applicatoion rooot by canging a line>>>>>>>>>>>


	Eg. search howudoin.pdf

	It displays all the resuts in a new line.
	You arre in user mode now. 
	You may scroll down all the options and enter the result folder/file .
	in USER MODE.

	**SEARCH was the best one to implement	!!!!!!!!

------------------------------------------------------------------------------------------




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  TAHTS ALL FOLKS  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



















