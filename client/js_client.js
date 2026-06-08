const BASE_URL = "http://localhost:8080/api";

async function printResponse(title, response) {
    console.log(`\n========== ${title} ==========`);
    console.log("Status HTTP:", response.status);

    const data = await response.json();
    console.log(data);
}

async function main() {
    console.log("Cliente JavaScript consumindo a Smart Home API");

    let response;

    response = await fetch(`${BASE_URL}/health`);
    await printResponse("Verificando API", response);

    response = await fetch(`${BASE_URL}/home`);
    await printResponse("Informações da casa", response);

    response = await fetch(`${BASE_URL}/devices`);
    await printResponse("Lista de dispositivos", response);

    response = await fetch(`${BASE_URL}/devices/2/on`, {
        method: "POST"
    });
    await printResponse("Ligando lâmpada 2", response);

    response = await fetch(`${BASE_URL}/lamps/2/brightness`, {
        method: "PUT",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({
            brightness: 35
        })
    });
    await printResponse("Alterando brilho da lâmpada 2", response);

    response = await fetch(`${BASE_URL}/sensors/4/temperature`);
    await printResponse("Lendo temperatura do sensor 4", response);

    response = await fetch(`${BASE_URL}/devices/2/off`, {
        method: "POST"
    });
    await printResponse("Desligando lâmpada 2", response);
}

main();