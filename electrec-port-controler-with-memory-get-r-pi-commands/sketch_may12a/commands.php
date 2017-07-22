
<?php
if (isset($_POST['command']))
{
    switch($_POST['command'])
    {
        case "fan":
        $command = escapeshellcmd("python ".$_POST['command'].".py");
        $output = shell_exec($command);
        echo $output;
        break;

        case "light":
        $command = escapeshellcmd("python ".$_POST['command'].".py");
        $output = shell_exec($command);
        echo $output;
        break;

        case "skimmer":
        $command = escapeshellcmd("python ".$_POST['command'].".py");
        $output = shell_exec($command);
        echo $output;
        break;

        case "upload":
        $command = escapeshellcmd("python ".$_POST['command'].".py");
        $output = shell_exec($command);
        echo $output;
        break;

        case "wave":
        $command = escapeshellcmd("python ".$_POST['command'].".py");
        $output = shell_exec($command);
        echo $output;
        break;

        /*case "fan":
        $command = escapeshellcmd("python ".$_POST['command'].".py");
        $output = shell_exec($command);
        echo $output;
        break;
*/
        


    }  

}


?>