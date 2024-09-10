// TODO: Add code to check answers to questions
// Check that the document is loaded before running script
document.addEventListener('DOMContentLoaded', function() {

    // Get all buttons
    let buttons = document.querySelectorAll('button');
    let message = document.getElementById('message');

    // Add event listeners for each button
    buttons.forEach(button => {
        button.addEventListener('click', function() {

            // Reset button BG color for all buttons
            buttons.forEach(b => b.classList.remove('correct', 'incorrect'));

            // Check if correct button selectedSet BG color for selected button
            if (button.id === 'mario') {
                button.classList.add('correct');
                message.textContent = 'Correct!'
                message.style='message'
            } else {
                button.classList.add('incorrect');
                message.textContent = 'Incorrect.'
            }
        });
    });

    let submit_button = document.getElementById('submit');
    let text_area = document.getElementById('user_input');
    let message2 = document.getElementById('message2');

    submit_button.addEventListener('click', function() {
        var answer = text_area.value.trim().toLowerCase();

        // alert("Answer: " + answer);

        if (answer === 'tetris') {
            text_area.style.backgroundColor = 'green';
            message2.textContent = 'Correct!'

        } else {
            text_area.style.backgroundColor = 'red';
            message2.textContent = 'Incorrect.'
        }
    });
});
