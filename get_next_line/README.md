<img width="1047" alt="Ekran Resmi 2023-03-10 18 06 09" src="https://user-images.githubusercontent.com/101333030/224553136-14b97532-7018-4139-b2dd-ed57eeb94f92.png">

🖋️ In this project, we are designing a function that allows us to read the content of a file (for example, poems.txt file) whose content we need to read, line by line.
For example, let's say we have a file named poems.txt. 
Many poems have been written in this file. 
Our goal is to pass the poem in this file to a marker. 
Why are we doing this? 
Because suppose there are words with misspellings in the poem. 
Before we can replace these words, we need to assign the poem in the file to a marker. 
Then we can reach the word of the poem we want from this pointer and make changes. 
Then in our code i.e. main we use a new file generator and create a file. 
We can write our newly changed poem in this file. 
So where did we use the get_next_line function? 
We give this function the file_identifier(search) of the file we want to read. 
And every time we call this function, it returns the first line of the file for which we have given the file_descriptor. 
If we call the function again, it returns line 2 of our file. 
It returns line 3 of our file the next time we call it. 
Thus, it allows us to progress as much as we want line by line. 
By assigning these returning lines to another pointer, we pull the content of the file we want into our code, that is, we pull it to a pointer in our code. 
This way we can play with the content in our marker and then use that content however we want. 
You can better understand why we use this get_next_line in my other projects, which we will use very often in other projects.

📈 The benefits I gained while doing this project: Algorithm Development Benefit, Open and Read functions, the concept of file_descriptor, the cases where we should use "free", why the arrays should end with '/n', the pointer being null and the first character of the pointer being null I learned that their situations are different from each other.

📅 Date I developed the project: March 2022. (My upload date to Github is March 2023)

💁 My advice to Ecole 42 students is that you may not understand why we made the get_next_line function in this project and why we should use it when you finish this project. Don't worry. You will easily understand why you should use it in future projects. But in the project you have to learn the concepts of 'open' and 'read'. Do not leave any lines of code in your get_next_line project that you do not know the meaning of. Also do lots of different experiments in main. For example, find the file descriptor of the get_next_line.c file you wrote and print this file to the end with the get_next_line function in main. Also, if you do the bonus part, please don't pass it off with shallow information. Learn the difference in Bonus well. Experiment with the bonus on Main.

🙏 Many thanks to <a href="https://github.com/mkaramuk" target="_blank">Muhammed Karamuk</a> who told me about my mistakes and many important details in this project. You have a great explanation.
