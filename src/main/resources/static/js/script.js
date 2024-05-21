const pointsOutput = document.getElementById('output-container');
const graphDiv = document.getElementById('function-graph');
const functionSelector = document.getElementById('function-selector');

const initializeGraph = () => {
    Plotly.newPlot('function-graph', [{
        x: [],
        y: [],
        mode: 'lines',
        line: {
            color: 'blue',
            width: 1
        },
        name: 'Начальный график'
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
};

const getPoints = async () => {
    try {
        const selectedFunction = functionSelector.value;
        const shapes = graphDiv.layout.shapes;

        const dataToSend = {
            selectedFunction: selectedFunction,
            shapes: shapes
        }

        const response = await fetch('http://127.0.0.1:8080/send_points', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ data: dataToSend })
        });

        const functionLaTeX = await response.text();
        pointsOutput.innerHTML = functionLaTeX;

        const expression = functionLaTeX
            .replace(/\\left/g, '')
            .replace(/\\right/g, '')
            .replace(/\\,/g, '')
            .replace(/\^(\{([^}]+)\})/g, '^($2)')
            .replace(/y\s*=\s*/, '');

        const compiledFunction = math.compile(expression);

        const xValues = math.range(-10, 10, 0.1).toArray();
        const yValues = xValues.map(x => compiledFunction.evaluate({ x }));

        Plotly.addTraces(graphDiv, {
            x: xValues,
            y: yValues,
            mode: 'lines',
            line: {
                color: 'red',
                width: 3
            },
            name: 'Новая функция'
        });
    } catch (error) {
        console.error('Ошибка:', error)
    }
};

const clearGraph = () => {
    Plotly.purge(graphDiv);
    pointsOutput.innerHTML = '';
    initializeGraph();
};

initializeGraph();