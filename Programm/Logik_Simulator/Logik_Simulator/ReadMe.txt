// TODO: Write Instructions here

/** \mainpage Handbuch

  \section Einleitung Einleitung

  \image latex "../../Screenshot.pdf" "Anwendung" width=12cm

  In dieser Kurzanleitung sollen die wichtigsten Funktionen Logik-Simulators erkl�rt werden.

  \section Tutorial Die erste Boolesche Schaltung
  In diesen Abschnitt wird erkl�rt, wie man eine kleine Boolesche Schaltung mit Hilfe des
  Logik-Simulators erstellt.

  \subsection step1 Schritt 1: Starten Sie den Editor

  \subsection step2 Schritt 2: Hinzuf�gen des ersten Elementes
  Klicken Sie mit der linken Maustaste auf den Button \e Input (Siehe Abbildung Elementgruppe 1).
  Klicken sie auf einen beliebigen Punkt auf dem Canvas (4 in der Abbildung) um den Eingang hinzuzuf�gen.

  \subsection step3 Schritt 3: Hinzuf�gen des zweiten Elementes
  F�gen Sie nun ein \e And-Gatter auf die gleiche Art und Weise, wie das Input-Gatter hinzu.

  \subsection step4 Schritt 4: Verbinden der zwei Elemente
  Klicken sie nun mit der rechten Maustaste auf das Gatter\e Input.
  Dadurch ist es nun Selektiert, und f�rbt sich blau.
  Wenn Sie nun mit der linken Maustaste auf das \e Input-Gatter klicken und mit
  gedr�ckter Maustaste den Zeiger zu dem \e And-Gatter bewegen, werden Sie beim
  Loslassen der Maustaste feststellen, das die beiden Gatter nun verbunden sind.

  Auf diese Weise k�nnen sie noch weitere Gatter hinzuf�gen, und miteinander verbinden.

  \subsection step5 Schritt 5: Besondere Elemente
  Die meisten Gatter k�nnen mit 2 Eing�ngen verbunden werden.
  Die Ausnahmen daf�r bilden nur das \e Not-Gatter, die \e Fork und das \e Output-Gatter.

  Das "Not"-Gatter negiert den an ihm anliegenden Wert, wogegen die \e Fork aus einem Eingang 2 Ausg�nge macht.

  \subsection step6 Schritt 6: Vollenden der Schaltung
  Um die Schaltung zu vollenden, m�ssen sie nun noch die Ausg�nge ihrer Gatter mit \e Output Gattern verbinden.

  \section edit_circuit Ver�ndern der Schaltung
  Sie k�nnen erstellte Schaltungen auch wieder ver�ndern.

  \subsection move_gates Verschieben
  Wenn Sie ihre Gatter verschieben wollen, halten Sie die Maustaste �ber ein NICHT selektierten Gatter und verschieben es.

  \subsection remove_gates Gatter L�schen
  Um ein Gatter zu L�schen selektieren Sie es, und dr�cken die \e Entfernen-Taste.

  \subsection remove_signals L�sen von Verbindungen
  Um eine Verbindung zwischen 2 Gattern zu l�sen, halten Sie die \e STRG-Taste auf der Tastatur und fahren mit gedr�ckter Maustaste �ber
  die entsprechende Verbindung.

  \section simulate_circuit Starten der Simulation
  Wenn Sie ein \e Input-Gatter selektiert haben, k�nnen Sie �ber die Tasten \e 0 und \e 1 Werte zuweisen.
  Sie werden feststellen, das sich die Verbindungen zwischen den Gattern bei \e 1 rot und bei \e 0 schwarz f�rben.
  Haben Sie all ihre \e Input-Gatter eingestellt, k�nnen Sie entweder mittels der \e Enter-Taste, oder dem \e Play-Knopf (Gruppe 2 in der Abbildung) die Schaltung berechnen.

  \section load_n_save_circuit Laden und Speichern
  Um Eine Schaltung zu Speichen, dr�cken Sie einfach den \e Speicher-Knopf neben dem \e Play-Knopf (Gruppe 2 in der Abbildung).
  Um Eine Schaltung zu Laden, dr�cken Sie einfach den \e Lade-Knopf neben dem \e Play-Knopf (Gruppe 2 in der Abbildung).

  \section input_file Editieren einer Eingabe-Datei
  Um mehrere verschiedene Eingangsbelegungen nacheinander berechnen zu k�nnen,
  erstellen Sie sie eine Datei, nach folgendem Schema:

  (Am Beispiel von 3 Eingangsgattern)

  \verbatim
  True,False,True
  False,True,True
  False,True,False
  \endverbatim

  Jede Zeile steht dabei f�r einen extra Berechnungsschritt.
  Speichern Sie nun die Datei unter einem von Ihnen gew�hlten Namen mit der
  Endung \e .otto ab.
  Danach k�nnen Sie die Datei im Logik-Simulator �ber den zweiten �ffnen-Dialog (Gruppe 3 in der Abbildung) �ffnen.

  Um die Rechnung auszuf�hren klicken Sie nun auf den f�r mehrere Rechnungen vorgesehenen zweiten \e Play-Button.
  Ihr Ergebnis wird nun in eine <em> *.ottoput Datei </em>, die dem gleichen Schema wie die \e Otto-Datei geschrieben.

  \section tips Hinweise
  Die Statusleiste am untern Rand der Anwendung (5 in der Abbildung) gibt Ihnen hilfreiche Hinweise im Umgang mit dem Programm.

  \section uml UML-Diagramme
  Folgend finden sie eine Auswahl an UML-Diagrammen die diese Anwendung beschreiben.

  \image latex "../../Anwendungsfalldiagramm.pdf" "Anwendungsfalldiagramm - Einfache Berechnung" width=12cm
  \image latex "../../Sequenzdiagramm.pdf" "Sequenzdiagramm f�r MainForm_MouseUp" width=12cm
  \image latex "../../Zustandsdiagramm.pdf" "Zustandsdiagramm f�r einfache Berechnungen" height=23cm

 */
