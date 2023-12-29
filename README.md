
# Makefile

### Binary

- `./analog`

### Commands

- `make`: Build the release version.
- `make test`: Run the tests.
- `make val`: Run the release version with valgrind

---

## Help

```sh
-h              Show this help message and exit
-g FILE         Specify the output file
-t HOUR         Filter by hour (e.g., ./analog -t 12)
-e EXTENSION    Filter by extension (e.g., ./analog -e)
```

### Examples

```sh
# Basic analysis
./analog depart.log

# Filter by hour
./analog depart.log -t 12

# Filter by extension
./analog depart.log -e

# Generate .dot file
./analog depart.log -g graph.dot

# Multiple Cmommands
./analog depart.log -t 10 -e -g graph.dot
```
