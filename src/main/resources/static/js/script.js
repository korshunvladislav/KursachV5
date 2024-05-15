const pointsOutput = document.getElementById('output-container');
const graphDiv = document.getElementById('function-graph');
const functionSelector = document.getElementById('function-selector');

const getPoints = async () => {
    try {
        const selectedFunction = functionSelector.value;
        const shapes = graphDiv.layout.shapes;
        const response = await fetch('http://127.0.0.1:8080/send_points', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ shapes })
        });
        pointsOutput.innerHTML = await response.text();
    } catch (error) {
        console.error('Ошибка:', error)
    }
};

const clearGraph = () => {
    const update = { shapes: [] };
    Plotly.relayout(graphDiv, update);
    pointsOutput.innerHTML = '';
};

Plotly.newPlot('function-graph', [{
    x: [], 
    y: [], 
    mode: 'lines', 
    line: { color: 'blue' }
}], {
    title: 'Нарисуйте свой график',
    xaxis: {
        title: 'X',
        range: [-10, 10],
        scaleanchor: 'y'
    },
    yaxis: {
        title: 'Y',
        range: [-10, 10]
    },
    dragmode: 'drawopenpath'
});