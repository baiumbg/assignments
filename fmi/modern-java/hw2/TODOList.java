import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class TODOList {
    TODOList() {
        tasks = new ArrayList<Task>();
    }

    public void addTask(Task task) {
        tasks.add(task);
    }

    public void printByPriority() {
        List<Task> sortedTasks = new ArrayList<Task>(this.tasks);
        Collections.sort(sortedTasks);
        for (Task task: sortedTasks) {
            System.out.println(task);
        }
    }

    public void printInProgress() {
        List<Task> inProgress = this.tasks.stream().filter(task -> task.getStatus().equals(Task.TaskStatus.IN_PROCESS))
                .collect(Collectors.toList());
        for (Task task: inProgress) {
            System.out.println(task);
        }
    }

    public void printCloseToDeadline() {
        Date today = new Date();
        List<Task> closeToDeadline = this.tasks.stream().filter(task ->
                (TimeUnit.DAYS.convert(task.getDate().getTime() - today.getTime(), TimeUnit.MILLISECONDS) < 3) &&
                (TimeUnit.DAYS.convert(task.getDate().getTime() - today.getTime(), TimeUnit.MILLISECONDS) >= 0) &&
                ((task.getStatus().equals(Task.TaskStatus.IN_PROCESS)) ||
                        (task.getStatus().equals(Task.TaskStatus.INITIAL)))
        ).collect(Collectors.toList());
        for (Task task: closeToDeadline) {
            System.out.println(task);
        }
    }

    private ArrayList<Task> tasks;
}
