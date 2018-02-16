double MIN = 68.0;
double MAX = 72.0;

int logging_enabled;

extern void write_to_log(double);
extern int check_range(void);

void log_when_out_of_range(double temperature)
{
  if (logging_enabled && check_range ()
      && (temperature < MIN || temperature > MAX) {
    write_to_log (temperature);
  }
}
