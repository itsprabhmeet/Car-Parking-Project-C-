// Constants
const ResourceName = window.GetParentResourceName();

// State management
let isVisible = false;

// Event listeners
window.addEventListener('message', handleMessage);
document.addEventListener('DOMContentLoaded', initialize);

// Initialize the UI
function initialize() {
    setupEventListeners();
}

// Handle incoming NUI messages
function handleMessage(event) {
    const { type, data } = event.data;
    
    switch (type) {
        case 'show':
            showUI();
            break;
        case 'hide':
            hideUI();
            break;
        default:
            console.log(`Unknown message type: ${type}`);
    }
}

// UI visibility functions
function showUI() {
    document.body.style.display = 'block';
    isVisible = true;
}

function hideUI() {
    document.body.style.display = 'none';
    isVisible = false;
}

// Setup event listeners
function setupEventListeners() {
    // Example: Close UI on Escape key
    document.addEventListener('keydown', (event) => {
        if (event.key === 'Escape' && isVisible) {
            sendToClient('close');
        }
    });
}

// Send data to client
function sendToClient(action, data = {}) {
    fetch(`https://${ResourceName}/${action}`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    });
}