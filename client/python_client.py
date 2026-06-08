import requests

BASE_URL = "http://localhost:8080/api"


def print_response(title, response):
    print("\n==========", title, "==========")
    print("Status HTTP:", response.status_code)

    try:
        print(response.json())
    except Exception:
        print(response.text)


def main():
    print("Cliente Python consumindo a Smart Home API")

    response = requests.get(f"{BASE_URL}/health")
    print_response("Verificando API", response)

    response = requests.get(f"{BASE_URL}/home")
    print_response("Informações da casa", response)

    response = requests.get(f"{BASE_URL}/devices")
    print_response("Lista de dispositivos", response)

    response = requests.post(f"{BASE_URL}/devices/1/on")
    print_response("Ligando lâmpada 1", response)

    response = requests.put(
        f"{BASE_URL}/lamps/1/brightness",
        json={"brightness": 85}
    )
    print_response("Alterando brilho da lâmpada 1", response)

    response = requests.get(f"{BASE_URL}/sensors/3/temperature")
    print_response("Lendo temperatura do sensor 3", response)

    response = requests.post(f"{BASE_URL}/devices/1/off")
    print_response("Desligando lâmpada 1", response)


if __name__ == "__main__":
    main()