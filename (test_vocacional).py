import tkinter as tk
from tkinter import messagebox

class TestDeValores:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Test de Valores")

        # Crear un marco con una barra de desplazamiento vertical
        frame_scroll = tk.Frame(self.root)
        frame_scroll.pack(side=tk.RIGHT, fill=tk.Y)

        scrollbar = tk.Scrollbar(frame_scroll, orient=tk.VERTICAL)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        # Preguntas y opciones
        self.preguntas = [
            "1. En una situación de emergencia, ¿qué harías?",
            "2. ¿Cómo manejarías un conflicto con un amigo cercano?",
            "3. Ante un dilema ético, ¿qué factor considerarías más importante?",
            "4. ¿Cómo abordas las críticas?",
            "5. En un trabajo en equipo, ¿prefieres liderar o seguir?",
            "6. ¿Cómo manejarías el estrés?",
            "7. En tu tiempo libre, ¿qué actividad prefieres?",
            "8. ¿Qué cualidad valoras más en una amistad?",
            "9. ¿Cómo manejas la toma de decisiones importantes?",
            "10. En una discusión, ¿prefieres ser conciliador o firme en tu posición?",
            "11. ¿Qué es más importante para ti en una carrera: el salario o la satisfacción personal?",
            "12. ¿Cómo manejarías la crítica constructiva en el trabajo?",
            "13. Ante una situación de injusticia, ¿actuarías o te mantendrías al margen?",
            "14. ¿Cómo te sientes acerca de asumir riesgos?",
            "15. ¿Prefieres trabajar en un entorno estructurado o flexible?",
            "16. ¿Qué te motiva más en la vida: lograr metas personales o contribuir al bienestar de los demás?",
            "17. Ante un cambio inesperado, ¿cómo reaccionarías?",
            "18. En tus relaciones, ¿valoras más la independencia o la cercanía emocional?",
            "19. ¿Cómo manejas los cambios en tu planificación?",
            "20. ¿Qué es más importante para ti: la estabilidad o la aventura?"
        ]

        self.opciones = [
            ["a. Actuaría de inmediato para resolver la situación.", "b. Buscaría ayuda antes de tomar alguna acción.", "c. Esperaría a ver cómo evoluciona la situación."],
            ["a. Abordaría el problema de inmediato y expresaría mis sentimientos.", "b. Trataría de encontrar un compromiso y entender su perspectiva.", "c. Evitaría el conflicto y trataría de calmar la situación."],
            ["a. La legalidad.", "b. Las consecuencias para los involucrados.", "c. Los principios éticos y morales."],
            ["a. Aprecio las críticas como oportunidades para mejorar.", "b. Las acepto, pero a veces me afectan emocionalmente.", "c. No me siento cómodo/a con las críticas y las evito."],
            ["a. Prefiero liderar y tomar decisiones.", "b. Me siento cómodo/a tanto liderando como siguiendo.", "c. Prefiero seguir y apoyar las decisiones de otros."],
            ["a. Busco soluciones prácticas y organizo mi tiempo.", "b. Necesito momentos de descanso y relajación.", "c. Busco apoyo emocional y comprensión."],
            ["a. Practicar deportes o actividades físicas.", "b. Leer o disfrutar de actividades creativas.", "c. Socializar con amigos o familiares."],
            ["a. Lealtad y confianza mutua.", "b. Compatibilidad de intereses y actividades.", "c. Comunicación abierta y comprensión mutua."],
            ["a. Tomo decisiones después de analizar cuidadosamente las opciones.", "b. Pido opiniones y considero diferentes perspectivas antes de decidir.", "c. Temo tomar decisiones importantes y procrastino."],
            ["a. Busco un compromiso para mantener la armonía.", "b. Defiendo mi posición con respeto a las opiniones de los demás.", "c. Mantengo firmemente mi posición incluso si eso significa conflicto."],
            ["a. La satisfacción personal y el equilibrio entre trabajo y vida personal.", "b. El salario y las oportunidades de crecimiento profesional.", "c. La estabilidad financiera y las prestaciones laborales."],
            ["a. Aprecio la retroalimentación y la utilizo para mejorar.", "b. Me siento incómodo/a con la crítica y trato de evitarla.", "c. Ignoro la crítica y sigo mi propio camino."],
            ["a. Actuaría para corregir la injusticia, incluso si eso significa enfrentar desafíos.", "b. Me sentiría incómodo/a, pero consideraría la posibilidad de actuar.", "c. Evitaría involucrarme y trataría de mantenerme al margen."],
            ["a. Me siento cómodo/a asumiendo riesgos calculados.", "b. Prefiero evitar riesgos y tomar decisiones seguras.", "c. Suelo ser cauteloso/a y evito situaciones riesgosas."],
            ["a. Me adapto a ambientes de trabajo flexibles y sin una estructura rígida.", "b. Necesito una estructura y planificación claras en mi entorno laboral.", "c. Prefiero una combinación de estructura y flexibilidad."],
            ["a. Lograr metas personales y satisfacción individual.", "b. Contribuir al bienestar de los demás y hacer una diferencia en la comunidad.", "c. Equilibrar ambas metas personales y contribuciones sociales."],
            ["a. Adaptaría mis planes y buscaría nuevas oportunidades.", "b. Me sentiría incómodo/a, pero buscaría maneras de adaptarme.", "c. Me resistiría al cambio y preferiría mantener la estabilidad."],
            ["a. Valor la independencia y la autonomía en mis relaciones.", "b. Busco un equilibrio entre independencia y cercanía emocional.", "c. Valoro la cercanía emocional y la conexión profunda con los demás."],
            ["a. Acepto los cambios y me adapto fácilmente.", "b. Me siento incómodo/a con los cambios, pero puedo adaptarme con el tiempo.", "c. Prefiero mantener la planificación original y resistirme a los cambios."],
            ["a. La estabilidad y la previsibilidad en todas las áreas de mi vida.", "b. La aventura y la posibilidad de enfrentar lo desconocido.", "c. Una combinación de estabilidad y aventura."]
        ]

        # Variables para almacenar las respuestas
        self.respuestas = [tk.StringVar() for _ in range(len(self.preguntas))]

        # Crear y mostrar preguntas y opciones dentro del Canvas
        self.canvas = tk.Canvas(self.root, yscrollcommand=scrollbar.set)
        self.canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Conectar la barra de desplazamiento con el Canvas
        scrollbar.config(command=self.canvas.yview)

        # Frame interior para contener las preguntas y opciones
        interior_frame = tk.Frame(self.canvas)
        self.canvas.create_window((0, 0), window=interior_frame, anchor=tk.NW)

        # 🔧 Ajuste automático del área desplazable
        interior_frame.bind("<Configure>", lambda e: self.canvas.configure(scrollregion=self.canvas.bbox("all")))

        # Botón de evaluación
        btn_evaluar = tk.Button(self.root, text="Evaluar", command=self.evaluar_respuestas)
        btn_evaluar.pack(pady=10)

        # Crear y mostrar preguntas y opciones
        self.mostrar_preguntas(interior_frame)

    def mostrar_preguntas(self, frame):
        for i, pregunta in enumerate(self.preguntas):
            frame_pregunta = tk.Frame(frame)
            frame_pregunta.pack(pady=10)

            lbl_pregunta = tk.Label(frame_pregunta, text=pregunta)
            lbl_pregunta.pack(anchor=tk.W)

            if i < len(self.opciones):  # Verifica si el índice es válido
                for j, opcion in enumerate(self.opciones[i]):
                    rb_opcion = tk.Radiobutton(frame_pregunta, text=opcion, variable=self.respuestas[i], value=chr(97 + j))
                    rb_opcion.pack(anchor=tk.W)

        # (el scrollregion ya se actualiza con el bind en __init__)

    def evaluar_respuestas(self):
        # Obtener las respuestas del usuario
        respuestas_usuario = [respuesta.get() for respuesta in self.respuestas]

        # Validar que todas estén contestadas
        if any(r == "" for r in respuestas_usuario):
            messagebox.showwarning("Faltan respuestas", "Responde todas las preguntas antes de evaluar.")
            return

        # Evaluar las respuestas y proporcionar resultados
        resultado = self.obtener_resultado(respuestas_usuario)

        # Mostrar los resultados en un cuadro de mensaje
        messagebox.showinfo("Resultados", f"Tu perfil de valores es: {resultado}")

    def obtener_resultado(self, respuestas):
        # Lógica de evaluación robusta (evita KeyError)
        puntuaciones = {"a": 0, "b": 0, "c": 0}

        for respuesta in respuestas:
            if respuesta in puntuaciones:
                puntuaciones[respuesta] += 1

        opcion_maxima = max(puntuaciones, key=puntuaciones.get)

        if opcion_maxima == "a":
            return "Tus valores tienden a favorecer la acción inmediata y la toma de decisiones rápidas."
        elif opcion_maxima == "b":
            return "Tus valores se inclinan hacia la búsqueda de compromisos y la consideración de diferentes perspectivas."
        else:
            return "Tus valores sugieren una preferencia por la paciencia y la observación antes de actuar."

if __name__ == "__main__":
    app = TestDeValores()
    app.root.mainloop()
