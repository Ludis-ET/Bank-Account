flowchart
```mermaid
    flowchart TD;
    A([start])-->B[/input the capacity in gallon and miles per gallon/];
    B-->C["distance= miles per gallon*capacity in gallon"];
    C-->D[/print distance/];
    D-->E([end]);
```


flowchart
```mermaid
    flowchart TD;
  A((Start)) -->|User Input| B{Input}
  B -->|Condition| C[If-Else]
  C -->|True| D[Initialize Variables]
  D --> E[Initialization]
  C -->|False| F[Process]
  E --> G((End))
  F --> G((End))

```