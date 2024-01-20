```mermaid
    flowchart TD;
    A([start])-->B["
    intializations 

    total_numbers = 100,
    count = 1,
    logged_in_user = -1,
    system_constant = 1001;


    manager_password = 123,
    manager_account = 1001000,
    float manager_balance = 1.5;
    
    new_balance = -1;

    check_user = true,
    terminate=false;
    
    "];


    B-->C["
    
    intialising the account and balace array

    account[total_numbers][2] = {
        {manager_account,manager_password},
    }
    balance[total_numbers] = {{manager_balance}}

    "];


    C-->D{terminate = false}
    D -->|True| D[Initialize Variables]


    D -->|False| F[Process]
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
  D-->E([end]);

```