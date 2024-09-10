// Fetch header and footer components
fetch('/components/header.html')
    .then(response => response.text())
    .then(html => {
        document.getElementById('header-container').innerHTML = html;
    });

fetch('/components/footer.html')
    .then(response => response.text())
    .then(html => {
        document.getElementById('footer-container').innerHTML = html;
    });

// Alert message
let scriptExecuted = localStorage.getItem('scriptExecuted');

function showMessage() {
    let modal = new bootstrap.Modal(document.getElementById('customModal'), {
        backdrop: 'static',
        keyboard: false
    });

    modal.show();
}

// Declare & initialize sound file
var audio = new Audio('/assets/sfx-start.mp3');

// Play sound effect when user clicks on link
function playSound() {
    audio.play();
}

// Run alert script once
if (!scriptExecuted) {
    setTimeout(function() {
        showMessage();

        // play sound effect
        playSound();

        localStorage.setItem('scriptExecuted', true);
    }, 1000);
}

document.addEventListener("DOMContentLoaded", function() {
    var links = document.querySelectorAll(".nav-item");

    links.forEach(function(link) {
        link.addEventListener("click", function() {
            playSound();
        });
    });
});
