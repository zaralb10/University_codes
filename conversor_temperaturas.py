import tkinter as tk
from tkinter import ttk, messagebox

c_f = lambda c: (c * 9/5) + 32
c_k = lambda c: c + 273.15
f_c = lambda f: (f - 32) * 5/9
f_k = lambda f: (f - 32) * 5/9 + 273.15
k_c = lambda k: k - 273.15
k_f = lambda k: (k - 273.15) * 9/5 + 32


def calcular():
    try:
        valor = float(temp.get())
        opcion = combo.get()

        if opcion == "Celsius a Fahrenheit":
            r = c_f(valor)
        elif opcion == "Celsius a Kelvin":
            r = c_k(valor)
        elif opcion == "Fahrenheit a Celsius":
            r = f_c(valor)
        elif opcion == "Fahrenheit a Kelvin":
            r = f_k(valor)
        elif opcion == "Kelvin a Celsius":
            if valor < 0:
                raise ValueError
            r = k_c(valor)
        elif opcion == "Kelvin a Fahrenheit":
            if valor < 0:
                raise ValueError
            r = k_f(valor)
        else:
            messagebox.showwarning("Aviso", "Selecciona una conversión")
            return

        resultado.set(f"{r:.2f}")

    except ValueError:
        messagebox.showerror("Error", "Dato inválido")

root = tk.Tk()
root.title("Conversor de Temperatura")
root.resizable(False, False)
root.config(padx=15, pady=15)

temp = tk.StringVar()
resultado = tk.StringVar()
sexo = tk.StringVar()

ttk.Label(root, text="Conversor de Temperatura", font=("Arial", 12, "bold")).grid(row=0, column=0, columnspan=2)

ttk.Label(root, text="Temperatura:").grid(row=1, column=0, sticky="w")
ttk.Entry(root, textvariable=temp).grid(row=1, column=1)

ttk.Label(root, text="Unidades:").grid(row=2, column=0, sticky="w", pady=5)
combo = ttk.Combobox(
    root,
    state="readonly",
    values=[
        "Celsius a Fahrenheit",
        "Celsius a Kelvin",
        "Fahrenheit a Celsius",
        "Fahrenheit a Kelvin",
        "Kelvin a Celsius",
        "Kelvin a Fahrenheit"
    ]
)
combo.grid(row=2, column=1)

sexo_box = ttk.LabelFrame(root, text="Sexo")
sexo_box.grid(row=1, column=2, rowspan=2, padx=15)

ttk.Button(root, text="Calcular", command=calcular).grid(row=3, column=1, pady=10)

ttk.Label(root, text="Resultado:").grid(row=4, column=0, sticky="w")
ttk.Entry(root, textvariable=resultado, state="readonly").grid(row=4, column=1)

root.mainloop()
