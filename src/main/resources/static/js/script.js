const pointsOutput = document.getElementById('output-container');
const graphDiv = document.getElementById('function-graph');
const functionSelector = document.getElementById('function-selector');
let approximationDone = false;

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
    if (approximationDone) return;
    approximationDone = true;

    try {
        const selectedFunction = functionSelector.value;
        const shapes = graphDiv.layout.shapes;

        const dataToSend = {
            selectedFunction: selectedFunction,
            shapes: shapes
        }

        const response = await fetch('/send_points', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ data: dataToSend })
        });

        const functionLaTeX = await response.text();

        if (functionLaTeX.trim() === "") {
            pointsOutput.classList.add('hidden');
        } else {
            pointsOutput.innerHTML = `$$${functionLaTeX}$$`;
            pointsOutput.classList.remove('hidden');
            MathJax.typeset();
        }

        const expression = functionLaTeX
            .replace(/\\left/g, '')
            .replace(/\\right/g, '')
            .replace(/\\,/g, '')
            .replace(/\^(\{([^}]+)\})/g, '^($2)')
            .replace(/y\s*=\s*/, '');

        const compiledFunction = math.compile(expression);

        const xValues = math.range(-30, 30, 0.1).toArray();
        const yValues = xValues.map(x => compiledFunction.evaluate({ x }));

        Plotly.addTraces('function-graph', {
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
    pointsOutput.classList.add('hidden');
    approximationDone = false;
    initializeGraph();
};

initializeGraph();