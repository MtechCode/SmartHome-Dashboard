async function fetchData() {
    const response = await fetch("http://your_server_ip:5000/latest-data");
    const data = await response.json();
    return data;
}

async function updateCharts() {
    const data = await fetchData();
    
    temperatureChart.data.labels.push(new Date().toLocaleTimeString());
    temperatureChart.data.datasets[0].data.push(data.temperature.slice(-1)[0]);
    temperatureChart.update();

    humidityChart.data.labels.push(new Date().toLocaleTimeString());
    humidityChart.data.datasets[0].data.push(data.humidity.slice(-1)[0]);
    humidityChart.update();
}

const temperatureChart = new Chart(document.getElementById("temperatureChart"), {
    type: "line",
    data: {
        labels: [],
        datasets: [{
            label: "Temperature (°C)",
            data: [],
            borderColor: "rgba(255, 99, 132, 1)"
        }]
    }
});

const humidityChart = new Chart(document.getElementById("humidityChart"), {
    type: "line",
    data: {
        labels: [],
        datasets: [{
            label: "Humidity (%)",
            data: [],
            borderColor: "rgba(54, 162, 235, 1)"
        }]
    }
});

setInterval(updateCharts, 60000); // Aktualizacja co minutę
