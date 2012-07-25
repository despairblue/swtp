// TODO: Write Instructions here

/** \mainpage Handbuch

  \section Einleitung Einleitung

  \image latex "../../Screenshot.pdf" "Anwendung" width=12cm

  In dieser Kurzanleitung sollen die wichtigsten Funktionen Logik-Simulators erklärt werden.

  \section Tutorial Die erste Boolesche Schaltung
  In diesen Abschnitt wird erklärt, wie man eine kleine Boolesche Schaltung mit Hilfe des
  Logik-Simulators erstellt.

  \subsection step1 Schritt 1: Starten Sie den Editor

  \subsection step2 Schritt 2: Hinzufügen des ersten Elementes
  Klicken Sie mit der linken Maustaste auf den Button \e Input (Siehe Abbildung Elementgruppe 1).
  Klicken sie auf einen beliebigen Punkt auf dem Canvas (4 in der Abbildung) um den Eingang hinzuzufügen.

  \subsection step3 Schritt 3: Hinzufügen des zweiten Elementes
  Fügen Sie nun ein \e And-Gatter auf die gleiche Art und Weise, wie das Input-Gatter hinzu.

  \subsection step4 Schritt 4: Verbinden der zwei Elemente
  Klicken sie nun mit der rechten Maustaste auf das Gatter\e Input.
  Dadurch ist es nun Selektiert, und färbt sich blau.
  Wenn Sie nun mit der linken Maustaste auf das \e Input-Gatter klicken und mit
  gedrückter Maustaste den Zeiger zu dem \e And-Gatter bewegen, werden Sie beim
  Loslassen der Maustaste feststellen, das die beiden Gatter nun verbunden sind.

  Auf diese Weise können sie noch weitere Gatter hinzufügen, und miteinander verbinden.

  \subsection step5 Schritt 5: Besondere Elemente
  Die meisten Gatter können mit 2 Eingängen verbunden werden.
  Die Ausnahmen dafür bilden nur das \e Not-Gatter, die \e Fork und das \e Output-Gatter.

  Das "Not"-Gatter negiert den an ihm anliegenden Wert, wogegen die \e Fork aus einem Eingang 2 Ausgänge macht.

  \subsection step6 Schritt 6: Vollenden der Schaltung
  Um die Schaltung zu vollenden, müssen sie nun noch die Ausgänge ihrer Gatter mit \e Output Gattern verbinden.

  \section edit_circuit Verändern der Schaltung
  Sie können erstellte Schaltungen auch wieder verändern.

  \subsection move_gates Verschieben
  Wenn Sie ihre Gatter verschieben wollen, halten Sie die Maustaste über ein NICHT selektierten Gatter und verschieben es.

  \subsection remove_gates Gatter Löschen
  Um ein Gatter zu Löschen selektieren Sie es, und drücken die \e Entfernen-Taste.

  \subsection remove_signals Lösen von Verbindungen
  Um eine Verbindung zwischen 2 Gattern zu lösen, halten Sie die \e STRG-Taste auf der Tastatur und fahren mit gedrückter Maustaste über
  die entsprechende Verbindung.

  \section simulate_circuit Starten der Simulation
  Wenn Sie ein \e Input-Gatter selektiert haben, können Sie über die Tasten \e 0 und \e 1 Werte zuweisen.
  Sie werden feststellen, das sich die Verbindungen zwischen den Gattern bei \e 1 rot und bei \e 0 schwarz färben.
  Haben Sie all ihre \e Input-Gatter eingestellt, können Sie entweder mittels der \e Enter-Taste, oder dem \e Play-Knopf (Gruppe 2 in der Abbildung) die Schaltung berechnen.

  \section load_n_save_circuit Laden und Speichern
  Um Eine Schaltung zu Speichen, drücken Sie einfach den \e Speicher-Knopf neben dem \e Play-Knopf (Gruppe 2 in der Abbildung).
  Um Eine Schaltung zu Laden, drücken Sie einfach den \e Lade-Knopf neben dem \e Play-Knopf (Gruppe 2 in der Abbildung).

  \section input_file Editieren einer Eingabe-Datei
  Um mehrere verschiedene Eingangsbelegungen nacheinander berechnen zu können,
  erstellen Sie sie eine Datei, nach folgendem Schema:

  (Am Beispiel von 3 Eingangsgattern)

  \verbatim
  True,False,True
  False,True,True
  False,True,False
  \endverbatim

  Jede Zeile steht dabei für einen extra Berechnungsschritt.
  Speichern Sie nun die Datei unter einem von Ihnen gewählten Namen mit der
  Endung \e .otto ab.
  Danach können Sie die Datei im Logik-Simulator über den zweiten Öffnen-Dialog (Gruppe 3 in der Abbildung) öffnen.

  Um die Rechnung auszuführen klicken Sie nun auf den für mehrere Rechnungen vorgesehenen zweiten \e Play-Button.
  Ihr Ergebnis wird nun in eine <em> *.ottoput Datei </em>, die dem gleichen Schema wie die \e Otto-Datei geschrieben.

  \section tips Hinweise
  Die Statusleiste am untern Rand der Anwendung (5 in der Abbildung) gibt Ihnen hilfreiche Hinweise im Umgang mit dem Programm.

  \section uml UML-Diagramme
  Folgend finden sie eine Auswahl an UML-Diagrammen die diese Anwendung beschreiben.

  \image latex "../../Anwendungsfalldiagramm.pdf" "Anwendungsfalldiagramm - Einfache Berechnung" width=12cm
  \image latex "../../Sequenzdiagramm.pdf" "Sequenzdiagramm für MainForm_MouseUp" width=12cm
  \image latex "../../Zustandsdiagramm.pdf" "Zustandsdiagramm für einfache Berechnungen" height=23cm

 */
