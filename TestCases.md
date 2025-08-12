# Test Cases

## Test 1

```mermaid

    requirementDiagram

    functionalRequirement Req_01 {
        id: 1
        text: Renaming a file with changing of file contents within one Commit
        verifymethod: test
    }

    element test_entity {
        type: simulation
    }

    test_entity - satisfies -> Req_01
```

**Renaming + Change of Contents**

```mermaid

    gitGraph
        commit
        commit id: "Change file name + contents" type: HIGHLIGHT
```

<ins>Test Result:</ins>

- [x] Test passed
- [ ] Test failed

## Test 2

```mermaid

    requirementDiagram

    functionalRequirement Req_02 {
        id: 2
        text: Renaming a file on one branch with changing of file contents on other Branch
        verifymethod: test
    }

    element test_entity {
        type: simulation
    }

    test_entity - satisfies -> Req_02
```

**Renaming on one Branch + Change of Contents on other Branch**

```mermaid

    gitGraph
        commit
        branch test
        commit
        checkout main
        commit id: "Rename file" type: HIGHLIGHT
        checkout test
        commit id: "Change file contents (still seeing old file name)" type: HIGHLIGHT
        checkout main
        merge test
```

<ins>Test Result:</ins>

- [x] Test passed
- [ ] Test failed

## Test 3

```mermaid

    requirementDiagram

    functionalRequirement Req_03 {
        id: 3
        text: "Cherry-Pick a Commit from another Branch"
        verifymethod: test
    }

    element test_entity {
        type: simulation
    }

    test_entity - satisfies -> Req_03
```

**Cherry-Picking a Commit from another Branch**

```mermaid

    gitGraph
        commit id: "Bug-Fix"
        branch dev
        commit
        cherry-pick id: "Bug-Fix"
```

<ins>Test Result:</ins>

- [x] Test passed
- [ ] Test failed

## Test 5

```mermaid

    requirementDiagram

    functionalRequirement Req_05 {
        id: 5
        text: "Merge Commit from another Branch"
        verifymethod: test
    }

    element test_entity {
        type: simulation
    }

    test_entity - satisfies -> Req_05
```

**Merge Commit from another Branch**

```mermaid

    gitGraph
        commit
        branch test
        commit
        checkout main
        commit
        checkout main
        merge test
```

<ins>Test Result:</ins>

- [ ] Test passed
- [ ] Test failed