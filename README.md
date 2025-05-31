# Proyecto-Progra-2
C++ project 

| Rama                       | Responsabilidad                                         | Clases del UML                                                  |
| -------------------------- | ------------------------------------------------------- | --------------------------------------------------------------- |
| `feature/sistema-nomina`   | Lógica del Singleton, Empleado y generación de planilla | `SistemaNomina`, `Empleado`                                     |
| `feature/nomina-calculos`  | Cálculos brutos, netos y deducciones                    | `Nomina`, `IngresoBuilder`, `Ingreso` y subclases               |
| `feature/deducciones`      | Implementación de las deducciones y factory             | `DeduccionAbstracta`, `DeductionFactory`, `CCSS`, `Renta`, etc. |
| `feature/menu-controlador` | Menú y controlador                                      | `ControladorNomina`, `OpcionMenu`                               |
| `feature/adapter-iobjeto` | Implementación del patrón adapter                       | `IObjeto`, `ObjectAdapter`                                     |
