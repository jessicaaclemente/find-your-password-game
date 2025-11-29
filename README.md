# find your-password game
Code developed for algorithms course, where we built a game called "Find Your Password" in the C++ language. Basically, the code generates a random four-digit password, in the range of 1 to 6, and the user has ten attempts to guess it.

#how the game works?
<ul>
    <li>The computer generates a 4-digit password (e.g. 2415).</li>
    <li><li>The computer generates a 4-digit password (e.g. 2415).</li></li>
    <li>The player enters guesses.</li>
    <li>The game gives feedback for each digit using 3 symbols:</li>
</ul>

symbol	meaning
o	Correct digit in the correct position.
x	Digit exists in the password but in a different position.
_	Digit does not exist in the password.

technologies
<ul>
    <li>.rand() to generate the random digits.</li>
    <li><li>.fail() to verify the input.</li></li>
    <li>.clear() to reset the wrong input.</li>
    <li>.ignore() to clear the buffer.</li>
</ul>
