Aplikacja w języku C++ demonstrująca wykorzystanie wątków oraz mechanizmów synchronizacji w środowisku wielowątkowym.

Projekt nie stanowi realnej symulacji ruchu tramwajowego. 
Kontekst tramwajowy pełni wyłącznie rolę warstwy narracyjnej, wynikającej z osobistych zainteresowań autora,
NIE powinien być interpretowany jako próba modelowania rzeczywistych procesów transportowych.

Puszczanie każdego kursu tramwaju w osobnym wątku jest WYSOCE NIEOPTYMALNYM rozwiązaniem,
występuje głodzenie wątków, jest mało wydajne i w kontekście realnej symulacji nie ma sensu,
bo wyniki są skrajnie niedeterministyczne.

Idea tego programu polega na tym, żeby uruchomić na przykład 4-5 wątków, i wtedy
zademonstrować działający mechanizm synchronizacji oraz bezpieczny dostęp do zasobów współdzielonych.

PLIK .EXE to wersja tej samej logiki ale z GUI
